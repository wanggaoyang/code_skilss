#include <iostream>
#include "complex0.h"

Complex::Complex()//默认构造函数 
{  
	re=im=0; 
} 

Complex::Complex(double a, double b)//构造函数
{
	std::cout<<"now create a new complex\n";
	re =a;
	im =b;
}

Complex::~Complex()
{
	std::cout<<"Bye!\n";
}

Complex Complex::operator+(const Complex & b) const
{
	return Complex(re+b.re,im+b.im);
}

Complex Complex::operator-(const Complex & b) const
{
	return Complex(re-b.re,im-b.im);
}

Complex Complex::operator~()
{
	return Complex(-re,-im);
} 

std::ostream & operator<<(std::ostream & os,const Complex & c)//cout的>>操作符重载 
{
	os<<"("<<c.re<<","<<c.im<<"i)";
	return os;	
}

std::istream & operator>>(std::istream & os,Complex & c)//cin的>>操作符重载 
{
	std::cout<<"请输入实部re："<<std::endl;
	double shi;
	os>>shi;
	
	std::cout<<"请输入虚部im："<<std::endl;
	double xu;
	os>>xu;
	c.re=shi;
	c.im=xu;
	return os;	
}





/*Complex Complex::operator*(const Complex & b) const   //复数乘法这俩先不考虑，算法问题 
{
	return Complex(re*b.re+,im+b.im);
}

Complex operator*(double n) const
{
	return Complex(re+b.re,im+b.im);
}*/
