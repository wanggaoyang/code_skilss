#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

/**
 * �����ƶ��ࣺMovable
 * ���麯����move
 */
class Movable
{
public:
    virtual void move() = 0;
};

/**
 * ���幫�����ࣺBus
 * ���м̳��ƶ���
 * ���з���carry
 */
class Bus : public Movable
{
public:
    virtual void move()
    {
        cout << "Bus -- move" << endl;
    }
    
    void carry()
    {
        cout << "Bus -- carry" << endl;
    }
};

/**
 * ����̹���ࣺTank
 * ���м̳��ƶ���
 * ���з���fire
 */
class Tank :public Movable
{
public:
    virtual void move()
    {
        cout << "Tank -- move" << endl;
    }

    void fire()
    {
        cout << "Tank -- fire" << endl;
    }
};

/**
 * ���庯��doSomething������
 * ʹ��dynamic_castת������
 */
void doSomething(Movable *obj)
{
    obj->move();

    if(typeid(*obj)==typeid(Bus))
    {
       Bus *bus=dynamic_cast<Bus *>(obj);
        bus->carry();
    }

    if(typeid(*obj)==typeid(Tank))
    {
        Tank *tank=dynamic_cast<Tank *>(obj);
        tank->fire();
    }
}

int main(void)
{
    Bus b;
    Tank t;
    doSomething(&b);
    doSomething(&t);
    
    return 0;
}
