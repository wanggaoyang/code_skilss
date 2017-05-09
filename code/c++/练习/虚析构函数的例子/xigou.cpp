#include "xigou.h"
#include <iostream>
using namespace std;

Shape::Shape()
{
	cout<<"build_Shape()"<<endl;
}

Shape::~Shape()
{
	cout<<"~Shape()"<<endl;
}

double Shape::calcAera()
{
	cout<<"Shape_calcAera()"<<endl;
}

Coordinate::Coordinate(int x,int y)
{
	m_iX=x;
	m_iY=y;
	cout<<"build_Coordinate()"<<endl;
}

Coordinate::~Coordinate()
{
	cout<<"~Coordinate()"<<endl;
}

Circle::Circle(double r)
{
	cout<<"build_Circle()"<<endl;
	m_dR=r;
	m_pCenter=new Coordinate(3,4);
}

Circle::~Circle()
{
	cout<<"~Circle()"<<endl;
	delete m_pCenter;
	m_pCenter=NULL;
}

double Circle::calcAera()
{
	cout<<"Circle_calcAera"<<endl;
	return 3.14*m_dR*m_dR;
}
