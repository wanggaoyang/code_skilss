#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
private:
	std::string name;
	std::string account;
public:
	Account();//Ĭ�Ϲ��캯�� 
	Account(const std::string & no, const std::string & ao, double mon=0.0);//���캯��ԭ�� (��ʼ��)
	~Account();//�������� 
	double money;
	void in(double price);
	void out(double price);
	void show()const;
};

#endif
