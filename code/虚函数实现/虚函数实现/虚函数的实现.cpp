#include<iostream>
using namespace std;

class parent
{
	virtual void foo1(){}
	virtual void foo2(){}
	void foo3();
};

class child1 : public parent
{
	void foo1() {};
	void foo2() {};
};

class child2 : public parent
{
	void foo1() {};
	void foo2() {};
	void foo3();
};

int main()
{

}