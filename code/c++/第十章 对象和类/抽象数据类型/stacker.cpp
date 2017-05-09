#include <iostream>
#include <cctype>
#include "stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) 
{
	using namespace std;
	Stack st;
	char ch;
	unsigned long po;
	cout<<"Please enter A to add a purchase order,\n"<<"P to process a PO,or Q to quit.\n";
	while(cin>>ch&&toupper(ch)!='Q')
	{
		while(cin.get()!='\n')
			continue;
		if(!isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch(ch)
		{
			case 'A':
			case 'a':cout<<"Enter a PO number to add: ";
					 cin>>po;
					 if(st.isfull())
					 	cout<<"stack already full\n";
					 else 
					 	st.push(po);
					 break;
			case 'p':
			case 'P':if(st.isempty())
						cout<<"stack already full\n";
					 else
					 {
					 	st.pop(po);
					 	cout<<"PO#"<<po<<" popped\n";
					 }
					 break;
		}
		cout<<"Please enter A to add a purchased order,\n"
			<<"P tp process a PO,or Q to quit.\n";
	}
	cout<<"bye!";
	return 0;
}
