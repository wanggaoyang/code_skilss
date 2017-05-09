/*本例子很赞，包含了随机数生成函数，并创建文件将产生的随机数放入其中*/ 
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
	
	srand(time(NULL));//将随机时间设为随机数种子 
	for(int i = 0;i < n;++ i)
		ArrayOne.push_back(rand());//生成随机数并放入队列中 
	for(int i = 0;i < m;++ i)
		ArrayTwo.push_back(rand());
	
	fout.open("A.txt", ios_base::out | ios_base::trunc);//创建并打开文件 
	
	for(int i = 0;i < n;++ i)
		fout << ArrayOne[i] << ends;//队列中数据放入文件，ends为输出一个空字符 
	fout.close();

	fout.open("B.txt", ios_base::out | ios_base::trunc);
	for(int i = 0;i < m;++ i)
		fout << ArrayTwo[i] << ends;
	fout.close();
	
	return 0;
}
