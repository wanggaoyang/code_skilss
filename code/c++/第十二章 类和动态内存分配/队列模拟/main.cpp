#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 
const int MIN_PER_HR =60;
bool newcustomer(double x); //是否有新顾客来
 
int main(int argc, char** argv) 
{
	srand(time(0));
	cout<<"案例：银行自动业务办理机"<<endl;
	cout<<"请输入最大队列数：";
	int qs;
	cin>>qs;
	Queue line(qs);//创建队列类Line并赋给队列数
	
	cout<<"请输入仿真时间：";
	int hours;
	cin>>hours;
	long cyclelimit=MIN_PER_HR*hours;  //程序自动运行上限时间 
	
	cout<<"请输入每小时平均顾客数量：";
	double perhour;
	cin>>perhour;
	double min_per_cust;
	min_per_cust=MIN_PER_HR/perhour;  //程序自动运行上限时间 
	
	
	Item temp;//创建新顾客
	long turnaways=0;//队满时离开的人数 
	long customers=0; //加入排队的人数 
	long served=0; //仿真期间一共接受服务的人数 
	long sum_line=0; //队长 
	long wait_time=0; //等待时间 
	long line_wait=0; //全队等待时间
	
/*仿真过程实现*/
	for(int cycle=0;cycle<cyclelimit;cycle++)
	{
		if(newcustomer(min_per_cust))//有新的顾客
		{
			if(line.isfull())
				turnaways++;
			else
			{
				customers++;
				temp.set(cycle);//记录顾客到达时间
				line.enqueue(temp);//顾客入队	
			} 
		} 
		
		if(wait_time<=0&&!line.isempty())
		{
			line.dequeue(temp);
			wait_time=temp.ptime();//将随机得到的顾客交易时间赋给wait_time
			line_wait+=cycle-temp.when();
			served++;		
		} 
		if(wait_time>0)
			wait_time--;
		sum_line+=line.queuecount();
	} 

/*结果报告*/
	if(customers>0)
	{
		cout<<"共容纳顾客数： "<<customers<<endl;
		cout<<"共服务顾客数： "<<served<<endl;
		cout<<"逃跑顾客数： "<<turnaways<<endl;
		cout<<"平均队列长度：";
		cout.precision(2);//保留两位小数 
		cout.setf(ios_base::fixed,ios_base::floatfield);//输出格式设置 
		cout<<(double)sum_line/cyclelimit<<endl;
		cout<<"平均等待时间： "
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
