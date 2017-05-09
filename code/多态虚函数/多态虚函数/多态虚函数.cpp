#include<iostream>
using namespace std;

class Person {
public:
	Person() {};
	Person(Person &person)
	{
		cout << "copy constructor" << endl;
	}
	virtual void printf()
	{
		cout << "i am a person" << endl;
	}
};

class Chinese : public Person 
{
public:
	virtual void printf()
	{
		cout << "i am a Chinese" << endl;
	}
};

class Usa : public Person
{
public:
	virtual void printf()
	{
		cout << "i am a Usa" << endl;
	}
};

void printf_(Person &person)
{
	person.printf() ;
}

void test(Person person)
{
	cout << "oh shit" << endl;
}

int main()
{
	Person A;
	Chinese B;
	Usa C;
	A.printf();
	B.printf();
	C.printf();

	printf_(A);
	printf_(B);
	printf_(C);

	test(A);
	return 0;
}