#include <iostream>
using namespace std;

class Shape
{
public:
	Shape()
	{cout<<"Shape biuld!"<<endl;}
	virtual void cal(){cout<<"Shape"<<endl;};
};

class Circle :public Shape
{
public:
	Circle()
		{cout<<"Circle biuld!"<<endl;}
	virtual void cal(){cout<<"Circle"<<endl;};
};

class Tangle :public Shape
{
public:
	Tangle(){cout<<"Tangle biuld!"<<endl;}
	virtual void cal(){cout<<"Tangle"<<endl;};
};

int main()
{
	Shape *shape1=new Circle();
	shape1->cal();
	Shape *shape2=new Tangle();
	shape2->cal();
	return 0;
} 
