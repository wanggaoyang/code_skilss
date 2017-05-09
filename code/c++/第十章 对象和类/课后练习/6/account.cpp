#include <iostream>
#include "account.h"
Move::Move(double a, double b)//¹¹Ôìº¯Êý
{
	std::cout<<"now create a new plot\n";
	x =a;
	y =b;
}

Move::~Move()
{
	std::cout<<"Bye!\n";
}

Move::showmove() const
{
	std::cout<<"x:"<<x<<"  "<<"y:"<<y<<std::endl;
}

Move Move::add(const Move &m) const
{
	double x1=x+m.x;
	double y1=y+m.y;
	return Move(x1,y1);
}

void Move::reset(double a,double b)
{
	x=a;
	y=b;
}
