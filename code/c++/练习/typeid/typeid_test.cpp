#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	int vInt=10;//定义整形变量 
	int arr[2]={10,20};//定义整形数组 
	int *p=&vInt;//定义一个指针，指向整型变量
	int **p2p=&p;//定义一个指向指针的指针
	int *parr[2]={&vInt,&vInt};//定义一个指针数组，内部有两个指针变量
	int (*p2arr)[2]=&arr;//定义一个指针，指向有两个元素的数组
	
	cout<<"Declaration [int vInt=10] type=="<<typeid(vInt).name()<<endl;
	cout<<"Declaration [arr[2]={10,20} type=="<<typeid(arr).name()<<endl;
	cout<<"Declaration [int *p=&vInt] type=="<<typeid(p).name()<<endl;
	cout<<"Declaration [int **p2p=&p] type=="<<typeid(p2p).name()<<endl;
	cout<<"Declaration [int *parr[2]={&vInt,&vInt}] type=="<<typeid(parr).name()<<endl;
	cout<<"Declaration [int (*p2arr)[2]=&arr] type=="<<typeid(p2arr).name()<<endl;
	 
}

