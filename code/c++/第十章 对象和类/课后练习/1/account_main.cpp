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
	
	std::cout<<"�˻��������!������ʾ�˻���Ϣ�� \n";
	int st;
	for(st=0;st<STKS;st++)
		somebody[st].show();
	std::cout<<"Boffo �����5000�飬��֮ǰ�˻����Ϊ��"<<somebody[1].money<<std::endl; 
	somebody[1].in(5000);
	std::cout<<"����������˻����Ϊ��"<<somebody[1].money<<std::endl;
	return 0;
}
