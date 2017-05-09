#include <iostream>
#include <fstream>

const int strsize=20;
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct bop
{
	char fullname[strsize];
	char title[strsize];
	char bopname[strsize];
	int preference;
};

int main(int argc, char** argv) 
{
	char choice;
	int n=0;
	bop member[5]=//define 5 members' information
	{
		{"Wimp Macho","leader","shitman",0},
		{"Raki Rhodes","manager","debbyman",1},
		{"Celia Laiter","stuff","dirty hand",2},
		{"Hoppy Hipman","chairman","godness",0},
		{"Pat Hand","babe","what the fuck",1}
	};
	
	cout<<"Benevolent Order of Programmers Report"<<endl;
	cout<<"a. display by name      "<<"b. display by title"<<endl;
	cout<<"c. display by bopname   "<<"d. display by prefrence"<<endl;
	cout<<"q. quit"<<endl;
	
	cout<<"Enter your choice: "<<endl;
	cin>>choice;
	
	while(choice!='q')
	{
		switch(choice)
		{
			case 'a': for(n=0;n<5;n++)
						{
							cout<<member[n].fullname<<endl;
						}
				  		break;
			case 'b': for(n=0;n<5;n++)
						{
							cout<<member[n].title<<endl;
						}
				  		break;
			case 'c': for(n=0;n<5;n++)
						{
							cout<<member[n].bopname<<endl;
						}
				  		break;
			case 'd': for(n=0;n<5;n++)
						{
							if(member[n].preference==0)
								cout<<member[n].fullname<<endl;
							else if(member[n].preference==1)
								cout<<member[n].title<<endl;
							else if(member[n].preference==2)
								cout<<member[n].bopname<<endl;
							else 
								cout<<"sorry you wrong!"<<endl;
						}
			break;		  
		}
		cout<<"Enter your next choice:  "<<endl;
		cin>>choice;
	}
	cout<<"Bye!"<<endl;
	return 0;
}
