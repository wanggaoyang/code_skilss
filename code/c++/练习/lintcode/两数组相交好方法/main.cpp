#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
 
int main()
{
	cout << "Hello world!" << endl;
	//find the same value in the two big array!
	ifstream fin;
	vector<int> ArrayOne, ArrayTwo;
	vector<int> ResultArray;
	int tmpVal;
	char tmpChar;
	
	fin.open("A.txt", ios_base::in);//A文件中的数据读入队列 ArrayOne
	while(1)
	{
		fin >> tmpVal;//将所打开文件中的数据依次读入tmpVal变量中，每次读入一个值。 
		//fin >> tmpChar;
		if(fin.fail())
	       break;
		ArrayOne.push_back(tmpVal);//将读入的值依次放入队列中 
		cout<<ArrayOne.size()<<endl;//这我自己加的，为了看是不是正常读进来了 
	}
	fin.close();

	fin.open("B.txt");//B文件中的数据读入队列 ArrayTwo
	while(1)
	{
	    fin >> tmpVal;
		//fin >> tmpChar;
		if(fin.fail())
	       break;
		 ArrayTwo.push_back(tmpVal);
		 cout<<ArrayTwo.size()<<endl;//这我自己加的，为了看是不是正常读进来了 
	}
	fin.close();

	 //sort first  两个队列进行排序 
	sort(ArrayOne.begin(), ArrayOne.end());
	sort(ArrayTwo.begin(), ArrayTwo.end());
	/*自己设置一个循环看一下这个排序的效果*/
	for(int k=0;k<ArrayOne.size();k++)//自己加的，看排序效果 
		cout<<ArrayOne[k]<<ends; //自己加的，看排序效果 
 
	const int nSize1 = ArrayOne.size();//记录队列大小 
	const int nSize2 = ArrayTwo.size();//记录队列大小 
	//cmp job
	int nPointer1 = 0;
	int nPointer2 = 0;
	while(nPointer1 < nSize1 && nPointer2 < nSize2)//当两个指针都没有到最后 
	{
		while(ArrayOne[nPointer1] < ArrayTwo[nPointer2])//如果指针1的值小于指针2指向的值，则指针1指向下一个 
		{
	    	nPointer1 ++;
		}
		while(ArrayOne[nPointer1] > ArrayTwo[nPointer2])//如果指针2的值小于指针1指向的值，则指针2指向下一个 
		{
	    	nPointer2 ++;
		}
		if(ArrayOne[nPointer1] == ArrayTwo[nPointer2])//如果指两个指针所指的值相等了，则存在ResultArray队列中 
		{
			int tmpVal = ArrayOne[nPointer1];
		ResultArray.push_back(ArrayOne[nPointer1]);
		while(ArrayOne[nPointer1] == tmpVal)
			nPointer1++;
		while(ArrayTwo[nPointer2] == tmpVal)
			nPointer2++;
		}
		//nPointer1++;
		//nPointer2++;
	}
	
	cout<<"结果是"<<ends; //自己加的，看排序效果
	int nResultLength = ResultArray.size();
	for(int k=0;k<ResultArray.size();k++)//自己加的，看排序效果 
		cout<<ResultArray[k]<<ends; //自己加的，看排序效果 
	
	ofstream fout;
	fout.open("Result.txt", ios_base::out | ios_base::trunc);//将结果输出到文件当中 
	for(int i = 0;i < nResultLength;++ i)
	{
		fout << ResultArray[i] << ends;
	}
	fout.close();
	return 0;
}
