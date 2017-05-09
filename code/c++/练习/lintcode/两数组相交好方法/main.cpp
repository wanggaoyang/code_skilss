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
	
	fin.open("A.txt", ios_base::in);//A�ļ��е����ݶ������ ArrayOne
	while(1)
	{
		fin >> tmpVal;//�������ļ��е��������ζ���tmpVal�����У�ÿ�ζ���һ��ֵ�� 
		//fin >> tmpChar;
		if(fin.fail())
	       break;
		ArrayOne.push_back(tmpVal);//�������ֵ���η�������� 
		cout<<ArrayOne.size()<<endl;//�����Լ��ӵģ�Ϊ�˿��ǲ��������������� 
	}
	fin.close();

	fin.open("B.txt");//B�ļ��е����ݶ������ ArrayTwo
	while(1)
	{
	    fin >> tmpVal;
		//fin >> tmpChar;
		if(fin.fail())
	       break;
		 ArrayTwo.push_back(tmpVal);
		 cout<<ArrayTwo.size()<<endl;//�����Լ��ӵģ�Ϊ�˿��ǲ��������������� 
	}
	fin.close();

	 //sort first  �������н������� 
	sort(ArrayOne.begin(), ArrayOne.end());
	sort(ArrayTwo.begin(), ArrayTwo.end());
	/*�Լ�����һ��ѭ����һ����������Ч��*/
	for(int k=0;k<ArrayOne.size();k++)//�Լ��ӵģ�������Ч�� 
		cout<<ArrayOne[k]<<ends; //�Լ��ӵģ�������Ч�� 
 
	const int nSize1 = ArrayOne.size();//��¼���д�С 
	const int nSize2 = ArrayTwo.size();//��¼���д�С 
	//cmp job
	int nPointer1 = 0;
	int nPointer2 = 0;
	while(nPointer1 < nSize1 && nPointer2 < nSize2)//������ָ�붼û�е���� 
	{
		while(ArrayOne[nPointer1] < ArrayTwo[nPointer2])//���ָ��1��ֵС��ָ��2ָ���ֵ����ָ��1ָ����һ�� 
		{
	    	nPointer1 ++;
		}
		while(ArrayOne[nPointer1] > ArrayTwo[nPointer2])//���ָ��2��ֵС��ָ��1ָ���ֵ����ָ��2ָ����һ�� 
		{
	    	nPointer2 ++;
		}
		if(ArrayOne[nPointer1] == ArrayTwo[nPointer2])//���ָ����ָ����ָ��ֵ����ˣ������ResultArray������ 
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
	
	cout<<"�����"<<ends; //�Լ��ӵģ�������Ч��
	int nResultLength = ResultArray.size();
	for(int k=0;k<ResultArray.size();k++)//�Լ��ӵģ�������Ч�� 
		cout<<ResultArray[k]<<ends; //�Լ��ӵģ�������Ч�� 
	
	ofstream fout;
	fout.open("Result.txt", ios_base::out | ios_base::trunc);//�����������ļ����� 
	for(int i = 0;i < nResultLength;++ i)
	{
		fout << ResultArray[i] << ends;
	}
	fout.close();
	return 0;
}
