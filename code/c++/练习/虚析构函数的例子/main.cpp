#include <iostream>
#include "xigou.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Shape *shape1=new Circle(5);
	shape1->calcAera();
	
	delete shape1;
	shape1=NULL;
	return 0;
}
