#ifndef _COMPLEX_H_
#define _COMPLEX_H_
#include <iostream>

class Complex
{
private:
	double re;
	double im;
public:
Complex();

Complex(double a, double b);//sets x,y to a,b
	
~Complex();//析构函数 
	
Complex operator+(const Complex & b) const;
Complex operator-(const Complex & b) const;	
//Complex operator*(const Complex & b) const;
//Complex operator*(double n) const;
Complex operator~();//共轭	

friend std::ostream & operator<<(std::ostream & os,const Complex & c);//重载操作符<< 
friend std::istream & operator>>(std::istream & os,Complex & c);//重载操作符>> 这里类C的内容将会改变，所以去掉const 
};

#endif
