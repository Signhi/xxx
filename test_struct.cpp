#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct S1{
public:
    int a;
    int b;

    S1(int i, int j):a(i), b(j){}
};


class C1{
public:
    int a;
    int b;
    C1(int i, int j):a(i), b(j){}
};

int main(){
    vector<int> v = {1, 2, 3};
    for_each(v.begin(), v.end(), [](int& a){
        a++;
    });
    for_each(v.begin(), v.end(), [](int& a){
        cout << a << endl;
    });
    int a = 0;
    S1* s = new S1(1, 2);
    C1* c = new C1(1, 2);
    cout << &a << endl;
    cout << s << endl;
    cout << c << endl;
    return 0;
}