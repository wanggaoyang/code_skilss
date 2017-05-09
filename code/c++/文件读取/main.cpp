#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int SIZE=60;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	char filename[SIZE];
	ifstream inFile;
	cout<<"Enter the name of data file: ";
	cin.getline(filename,SIZE);
	inFile.open(filename);
	
	if(!inFile.is_open())
	{
		cout<<"Could not open babe"<<filename<<endl;
		exit(EXIT_FAILURE);
	}
	
	string str;
	
	inFile>>value;
	while(inFile.good())
	{
		++count;
		sum+=value;
		inFile>>value;
	}
	
	if(inFile.eof())
		cout<<"End of the file!\n";
	else if (inFile.fail())
		cout<<"Input terminated by data mismatch.\n";
	else 
		cout<<"Input terminated for unknown reason.\n";
		
	if(count==0)
		cout<<"No data processed.\n";
	else
	{
		cout<<"Item read: "<<count<<endl;
		cout<<"Sunm: "<<sum<<endl;
		cout<<"Average: "<<sum/count<<endl;
	}
	 
	inFile.close();

	return 0;
}
