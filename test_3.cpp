 
#include <iostream>
using namespace std;
 
class A {
public:
	A()
	{
		cout << "call A()" << endl;
	}
 
	~A()
	{
		cout << "call ~A()" << endl;
	}
	
};
 
class B
{
public:
	B(A value)
	{
        m_a = value;
		cout << "call B()" << endl;
		//m_a = value;
	}
 
	~B()
	{
		cout << "call ~B()" << endl;
	}
 
private:
	A m_a;
};
 
int main()
{
	A objA;
	B objB(objA);
    return 0;
}