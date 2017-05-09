#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <string>

class Account
{
private:
	std::string name;
	std::string account;
public:
	Account();//默认构造函数 
	Account(const std::string & no, const std::string & ao, double mon=0.0);//构造函数原型 (初始化)
	~Account();//析构函数 
	double money;
	void in(double price);
	void out(double price);
	void show()const;
};

#endif
