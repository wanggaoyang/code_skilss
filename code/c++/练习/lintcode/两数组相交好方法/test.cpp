/*�����Ӻ��ޣ���������������ɺ������������ļ����������������������*/ 
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	cout << "Hello world!" << endl;
	ofstream fout;
	vector<int> ArrayOne;
	vector<int> ArrayTwo;
	int n = 100;
	int m = 200;
	
	srand(time(NULL));//�����ʱ����Ϊ��������� 
	for(int i = 0;i < n;++ i)
		ArrayOne.push_back(rand());//�������������������� 
	for(int i = 0;i < m;++ i)
		ArrayTwo.push_back(rand());
	
	fout.open("A.txt", ios_base::out | ios_base::trunc);//���������ļ� 
	
	for(int i = 0;i < n;++ i)
		fout << ArrayOne[i] << ends;//���������ݷ����ļ���endsΪ���һ�����ַ� 
	fout.close();

	fout.open("B.txt", ios_base::out | ios_base::trunc);
	for(int i = 0;i < m;++ i)
		fout << ArrayTwo[i] << ends;
	fout.close();
	
	return 0;
}
