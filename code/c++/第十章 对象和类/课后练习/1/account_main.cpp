#include <iostream>
#include "account.h"

const int STKS=4;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) 
{
	Account somebody[STKS]=
	{
		Account("Nano","joe",500),
		Account("Boffo","ali",0),
		Account("Monolithic","alice",100),
		Account("Fleep","nobody",10000),
	};
	
	std::cout<<"账户创建完成!下面显示账户信息： \n";
	int st;
	for(st=0;st<STKS;st++)
		somebody[st].show();
	std::cout<<"Boffo 想存入5000块，他之前账户余额为："<<somebody[1].money<<std::endl; 
	somebody[1].in(5000);
	std::cout<<"存入后，他的账户余额为："<<somebody[1].money<<std::endl;
	return 0;
}
