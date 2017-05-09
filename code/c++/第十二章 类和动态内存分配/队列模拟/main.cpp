#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
const int MIN_PER_HR =60;
bool newcustomer(double x); //�Ƿ����¹˿���
 
int main(int argc, char** argv) 
{
	srand(time(0));
	cout<<"�����������Զ�ҵ������"<<endl;
	cout<<"����������������";
	int qs;
	cin>>qs;
	Queue line(qs);//����������Line������������
	
	cout<<"���������ʱ�䣺";
	int hours;
	cin>>hours;
	long cyclelimit=MIN_PER_HR*hours;  //�����Զ���������ʱ�� 
	
	cout<<"������ÿСʱƽ���˿�������";
	double perhour;
	cin>>perhour;
	double min_per_cust;
	min_per_cust=MIN_PER_HR/perhour;  //�����Զ���������ʱ�� 
	
	
	Item temp;//�����¹˿�
	long turnaways=0;//����ʱ�뿪������ 
	long customers=0; //�����Ŷӵ����� 
	long served=0; //�����ڼ�һ�����ܷ�������� 
	long sum_line=0; //�ӳ� 
	long wait_time=0; //�ȴ�ʱ�� 
	long line_wait=0; //ȫ�ӵȴ�ʱ��
	
/*�������ʵ��*/
	for(int cycle=0;cycle<cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))//���µĹ˿�
		{
			if(line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//��¼�˿͵���ʱ��
				line.enqueue(temp);//�˿����	
			} 
		} 
		
		if(wait_time<=0&&!line.isempty())
		{
			line.dequeue(temp);
			wait_time=temp.ptime();//������õ��Ĺ˿ͽ���ʱ�丳��wait_time
			line_wait+=cycle-temp.when();
			served++;		
		} 
		if(wait_time>0)
			wait_time--;
		sum_line+=line.queuecount();
	} 

/*�������*/
	if(customers>0)
	{
		cout<<"�����ɹ˿����� "<<customers<<endl;
		cout<<"������˿����� "<<served<<endl;
		cout<<"���ܹ˿����� "<<turnaways<<endl;
		cout<<"ƽ�����г��ȣ�";
		cout.precision(2);//������λС�� 
		cout.setf(ios_base::fixed,ios_base::floatfield);//�����ʽ���� 
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<"ƽ���ȴ�ʱ�䣺 "
			<<(double) line_wait / served <<"minutes"<<endl;
	}
	else
		cout<<"No customers!"<<endl;
	cout<<"Done!"<<endl;	
	return 0;
}

bool newcustomer(double x)
{
	return (rand()*x/RAND_MAX<1);
}
