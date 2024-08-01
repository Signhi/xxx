#include <iostream>
#include <hiredis/hiredis.h>

int main() {
    redisContext* c = redisConnect("127.0.0.1", 6379);
    if (c == nullptr || c->err) {
        if (c) {
            std::cerr << "Connection error: " << c->errstr << std::endl;
            redisFree(c);
        } else {
            std::cerr << "Connection error: can't allocate redis context" << std::endl;
        }
        return 1;
    }

    // 设置键为 "key_name"，值为 "Hello Redis!"
    redisReply* reply = (redisReply*)redisCommand(c, "SET key_name Hello");
    if (reply == nullptr) {
        std::cerr << "Failed to execute SET command: " << c->errstr << std::endl;
        redisFree(c);
        return 1;
    }
    std::cout << "SET command: " << reply->str << std::endl;
    freeReplyObject(reply);

    // 获取键 "key_name" 的值
    reply = (redisReply*)redisCommand(c, "GET key_name");
    if (reply == nullptr) {
        std::cerr << "Failed to execute GET command: " << c->errstr << std::endl;
        redisFree(c);
        return 1;
    }
    std::cout << "GET key_name: " << reply->str << std::endl;
    freeReplyObject(reply);

    redisFree(c);

    return 0;
}
