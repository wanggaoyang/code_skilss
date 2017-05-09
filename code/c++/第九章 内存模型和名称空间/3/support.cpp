#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
extern double warming;
void update(double dt);
void local();

void update(double dt)
{
	extern double warming;
	warming+=dt;
	cout<<warming;
}

void local()
{
	double warming=0.8;
	cout<<warming;
	cout<<warming;
}
