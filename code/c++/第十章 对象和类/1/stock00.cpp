#include <iostream>
#include "stock00.h"

Stock::Stock()//默认构造函数 
{
	std::cout<<"默认构造函数";
	company ="no name";
	shares=0;
	share_val=0;
	total_val=0;
}

Stock::Stock(const std::string & co ,long n ,double pr)//构造函数的定义 
{
	std::cout<<"Constructor using "<<co<<"called\n";
	company =co;
	if(n<0)
	{
		std::cout<<"Number of shares can't be negative;"<<company<<"shares set to 0.\n";
		shares=0;
	}
	else
		shares=n;
	share_val=pr;
	set_tot();
}

Stock::~Stock()
{
	std::cout<<"Bye, "<<company<<"!\n";
}

void Stock::buy(long num ,double price)
{
	if(num<0)
	{
		std::cout<<"Number of shares perchases can't be negative;\n";
	}
	else
	{
		shares+=num;
		share_val=price;
		set_tot();
	}	
}

void Stock::sell(long num ,double price)
{
	using std::cout;
	if(num<0)
	{
		cout<<"Number of shares sold can't be negative;\n";
	}
	else if(num>shares)
	{
		cout<<"too more baby;\n";
	}	
	else
	{
		shares-=num;
		share_val=price;
		set_tot();
	}	
}

void Stock::update(double price)
{
	share_val=price;
	set_tot();
}

void Stock::show() const
{
	std::cout<<"company: "<<company
			 <<"shares: "<<shares<<'\n'
			 <<"share princes: $ "<<share_val
			 <<"total worth: $ "<<total_val<<'\n';
}

const Stock & Stock::topval(const Stock & s) const//比较函数 
{
	if(s.total_val>total_val)
		return s;
	else
		return *this;
} 

