#include<iostream>
using namespace std;

class X{};
class A{};
class B:public A{};
class C:public B{};
class D:public X ,public C{};

int main()
{
	A *pa = new D;
	X *px = dynamic_cast <X*>(pa);
	return 0;
}