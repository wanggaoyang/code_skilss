#ifndef QUEUE_H_
#define QUEUE_H_ 

/*�ͻ�������*/
class Customer
{
private:
	long arrive;//�˿͵���ʱ�� 
	int processtime;//�˿ͽ���ʱ�� 
public:
	Customer(){arrive=processtime=0;}//Ĭ�Ϲ��캯����ǿ��ת��
	void set(long when);//�˿͵Ĵﵽʱ��ͽ���ʱ���趨���� 
	long when() const{return arrive;}//��ȡ�˿͵���ʱ�� 
	int ptime() const{return processtime;} //��ȡ�˿ͽ���ʱ��
};

/*��䲻�ܷ�ǰ�棬��Ϊ��û�����ǻ�û������*/ 
typedef Customer Item;//�����е�Customer �滻ΪItem 

/*����������*/ 
class Queue
{
private:
	enum {Q_SIZE=10};//ö�٣��������Ԫ��Ϊ10
	struct Node {Item item;struct Node * next;};//�������ݵı�ʾ 
	Node * front;//����ָ���ͷ��Ԫ��
	Node * rear;//����ָ���β��Ԫ��
	int items;//�������ִ�Ԫ������
	const int qsize;//������Ԫ�����ֵ 
	
	Queue(const Queue &q) : qsize(0) {}    //���������ֱ��Ǹ��ƹ��캯����ִ����ȸ��Ƶĸ�ֵ����� 
	Queue &operator=(const Queue &q){return *this;}//�����ò������ȷ��ţ�������� 
public:
	Queue(int qs=Q_SIZE);//���캯��
	~Queue();//�������� 
	bool isempty() const; //�п� 
	bool isfull() const; //����
	int queuecount() const;//���㵱ǰ������Ԫ������
	bool enqueue(const Item & item);//������м���Ԫ��
	bool dequeue(Item & item);//ɾ�������е�Ԫ�� 
};

#endif
	
	

