#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;


int str_to_int1(string & str)
{
	std::stringstream ss;
	ss<<str;
	int n;
	ss>>n;
	ss.clear();
	return n;
}

int str_to_int2(string & str)
{
	return atoi(str.c_str());
}

int main()
{	
	string str1="12345"; 
	string str2="2";
	int rel1=str_to_int1(str1);	
	
	int rel2=str_to_int2(str2);
	
	int result=rel1+rel2;
	cout<<rel1<<"+"<<rel2<<"="<<result<<endl;
	
	string str3=str1+str2;
	cout<<str3<<endl;
	
	return 0;
}
