#include <iostream>
#include "complex0.h"

Complex::Complex()//Ĭ�Ϲ��캯�� 
{  
	re=im=0; 
} 

Complex::Complex(double a, double b)//���캯��
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

std::ostream & operator<<(std::ostream & os,const Complex & c)//cout��>>���������� 
{
	os<<"("<<c.re<<","<<c.im<<"i)";
	return os;	
}

std::istream & operator>>(std::istream & os,Complex & c)//cin��>>���������� 
{
	std::cout<<"������ʵ��re��"<<std::endl;
	double shi;
	os>>shi;
	
	std::cout<<"�������鲿im��"<<std::endl;
	double xu;
	os>>xu;
	c.re=shi;
	c.im=xu;
	return os;	
}





/*Complex Complex::operator*(const Complex & b) const   //�����˷������Ȳ����ǣ��㷨���� 
{
	return Complex(re*b.re+,im+b.im);
}

Complex operator*(double n) const
{
	return Complex(re+b.re,im+b.im);
}*/
