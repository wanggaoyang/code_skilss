#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	int vInt=10;//�������α��� 
	int arr[2]={10,20};//������������ 
	int *p=&vInt;//����һ��ָ�룬ָ�����ͱ���
	int **p2p=&p;//����һ��ָ��ָ���ָ��
	int *parr[2]={&vInt,&vInt};//����һ��ָ�����飬�ڲ�������ָ�����
	int (*p2arr)[2]=&arr;//����һ��ָ�룬ָ��������Ԫ�ص�����
	
	cout<<"Declaration [int vInt=10] type=="<<typeid(vInt).name()<<endl;
	cout<<"Declaration [arr[2]={10,20} type=="<<typeid(arr).name()<<endl;
	cout<<"Declaration [int *p=&vInt] type=="<<typeid(p).name()<<endl;
	cout<<"Declaration [int **p2p=&p] type=="<<typeid(p2p).name()<<endl;
	cout<<"Declaration [int *parr[2]={&vInt,&vInt}] type=="<<typeid(parr).name()<<endl;
	cout<<"Declaration [int (*p2arr)[2]=&arr] type=="<<typeid(p2arr).name()<<endl;
	 
}

