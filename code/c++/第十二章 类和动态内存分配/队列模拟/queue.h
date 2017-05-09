#ifndef QUEUE_H_
#define QUEUE_H_ 

/*客户类声明*/
class Customer
{
private:
	long arrive;//顾客到达时间 
	int processtime;//顾客交易时间 
public:
	Customer(){arrive=processtime=0;}//默认构造函数，强制转换
	void set(long when);//顾客的达到时间和交易时间设定函数 
	long when() const{return arrive;}//获取顾客到达时间 
	int ptime() const{return processtime;} //获取顾客交易时间
};

/*这句不能放前面，因为还没有这是还没有声明*/ 
typedef Customer Item;//将所有的Customer 替换为Item 

/*队列类声明*/ 
class Queue
{
private:
	enum {Q_SIZE=10};//枚举，队列最多元素为10
	struct Node {Item item;struct Node * next;};//队列数据的表示 
	Node * front;//定义指向队头的元素
	Node * rear;//定义指向队尾的元素
	int items;//队列中现存元素数量
	const int qsize;//队列中元素最大值 
	
	Queue(const Queue &q) : qsize(0) {}    //这俩东西分别是复制构造函数和执行深度复制的赋值运算符 
	Queue &operator=(const Queue &q){return *this;}//这里用不到，先放着，避免错误 
public:
	Queue(int qs=Q_SIZE);//构造函数
	~Queue();//析构函数 
	bool isempty() const; //判空 
	bool isfull() const; //判满
	int queuecount() const;//计算当前队列中元素数量
	bool enqueue(const Item & item);//向队列中加入元素
	bool dequeue(Item & item);//删除队列中的元素 
};

#endif
	
	

