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
	
~Complex();//�������� 
	
Complex operator+(const Complex & b) const;
Complex operator-(const Complex & b) const;	
//Complex operator*(const Complex & b) const;
//Complex operator*(double n) const;
Complex operator~();//����	

friend std::ostream & operator<<(std::ostream & os,const Complex & c);//���ز�����<< 
friend std::istream & operator>>(std::istream & os,Complex & c);//���ز�����>> ������C�����ݽ���ı䣬����ȥ��const 
};

#endif
