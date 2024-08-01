#include <mingw.thread.h>
#include <mingw.condition_variable.h>
#include <mingw.mutex.h>
#include <iostream>

using namespace std;

mutex mtx;
condition_variable cv;
int target = 1;

void print_num(int start, int tag, int max_num){
    for(int ii = start; ii <= max_num; ii += 3){
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [tag, ii](){
            return (ii % 3) == target;
        });
        target = (target + 1) % 3;
        cout << ii << endl;
        cv.notify_all();
    }
}

int main(){
    int max_num = 10000000;
    thread t_1(print_num, 1, 1, max_num);
    thread t_2(print_num, 2, 2, max_num);
    thread t_3(print_num, 3, 0, max_num);
    t_1.join();
    t_2.join();
    t_3.join();
    return 0;
}