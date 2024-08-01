#include <iostream>

using namespace std;


void test(int& a){
    int b = 4;
    a = b;
    return ;
}

int main(){
    int c = 2;
    int& d = c;
    int e = 2;
    d = e;
    test(c);
    return 0;
}