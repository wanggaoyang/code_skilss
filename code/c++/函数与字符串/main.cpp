#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct rect
{
	double x;
	double y;
};

struct polar
{
	double distance;
	double angle;
};

polar count(rect wait_to_change);

int main(int argc, char** argv) 
{
	rect himan;
	himan.x=30;
	himan.y=40;

	polar heygirl=count(himan);
	cout<<heygirl.angle<<endl;
	cout<<heygirl.distance<<endl;
	
	return 0;
}

polar count(rect wait_to_change)
{
	polar baby;
	baby.distance=sqrt(wait_to_change.x*wait_to_change.x+wait_to_change.y*wait_to_change.y);
	baby.angle=atan2(wait_to_change.y,wait_to_change.x);
	return baby;
}
