#include <iostream>
#include "account.h"

Account::Account()//Ĭ�Ϲ��캯�� 
{
	std::cout<<"Ĭ�Ϲ��캯��";
	name ="no name";
	account ="empty";
	money=0;
}

Account::Account(const std::string & no, const std::string & ao, double mon)//���캯���Ķ��� 
{
	std::cout<<"now create a new account "<<no<<"\n";
	name =no;
	account=ao;
	money=mon;
}

Account::~Account()
{
	std::cout<<"Bye, "<<name<<"!\n";
}

void Account::in(double price)
{
	if(price<0)
	{
		std::cout<<"baby you just can't in negative money! \n";
	}
	else
	{
		money+=price;
	}	
}

void Account::out(double price)
{
	using std::cout;
	if(price<0)
	{
		std::cout<<"baby you just can't out negative money! \n";
	}
	else if(price>money)
	{
		cout<<"too more baby;\n";
		price=money;
		std::cout<<"Now all your money will be purchased! \n";
		money=0;
	}	
	else
	{
		money-=	price;
	}	
}

void Account::show() const
{
	std::cout<<"name: "<<name<<'\n'
			 <<"account: "<<account<<'\n'
			 <<"total money: $ "<<money<<'\n';
}

