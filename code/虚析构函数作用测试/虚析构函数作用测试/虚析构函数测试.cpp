//#include<iostream>
//using namespace std;
//
//class Base {
//public:
//	Base() {};
//	~Base() 
//	{ 
//		cout << "Output from Base!" << endl; 
//	};
//
//	void DoSomething() 
//	{ 
//		cout << "Do something in class Base!" << endl; 
//	};
//};
//
//class Derived : public Base {
//public:
//	Derived() {};
//	~Derived() 
//	{ 
//		cout << "Output from Derived!" << endl; 
//	};
//
//	void DoSomething() 
//	{ 
//		cout << "Do something in class Derived!" << endl; 
//	};
//};
//
//int   main() {
//	Derived *p = new Derived;  //继承类对象调用继承类函数，先析构继承对象，再析构基类
//	p->DoSomething();
//	delete p;
//	return 0;
//}