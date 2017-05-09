#include <iostream>
#include <string>
using namespace std;
int lengthOfLastWord(string& s)
{
    // Write your code here
    int size=s.size();
    int count,i;
    for(i=0;i<size;i++)
    {
    	if(s[i]!=' ')
			count++;
		else
			count=0;
	}
	cout<<count<<endl;
	        
}

int main()
{
	string str="Hello World babbyaa";
	lengthOfLastWord(str);
	return 0;
} 
