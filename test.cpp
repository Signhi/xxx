#include <iostream>
#include <thread>
#include <mingw.mutex.h>
#include <mingw.condition_variable.h>
#include <mingw.thread.h>

using namespace std;
mutex mtx;
condition_variable cv;
bool target = TRUE;


void print_num(int start, bool target_1, int max_num){
    for(int ii = start; ii <= max_num; ii = ii + 2){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [target_1](){
            return target_1 == target;
        });
        cout << ii << endl;
        target = !target;
        lock.unlock();
        cv.notify_one();
    }
}

int main(){
    int max_num = 100;
    thread t_1(print_num, 1, TRUE, 100);
    thread t_2(print_num, 2, FALSE, 100);
    t_1.join();
    t_2.join();
    return 0;
}