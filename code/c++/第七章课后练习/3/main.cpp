#include <iostream>
#include <cctype>
#include <string>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string change(string & str);

int main(int argc, char** argv) 
{
	string s;
	string get;
	cout<<"Please input a string(q to qiut): "<<endl;
	getline(cin,s);
	while(s!="q")
		{
			get=change(s);
			cout<<get<<endl;
			cout<<"Now next string(q to qiut): "<<endl;
			getline(cin,s);
		}
	cout<<"Bye"<<endl;
	return 0;
}

string change(string & s)
{
	int size=s.length();  
	for(int i=0;i<size;i++)  
    {  
        s[i]=toupper(s[i]);  
    }  
    return s;
}

