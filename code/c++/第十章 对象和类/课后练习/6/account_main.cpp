#include <iostream>
#include "account.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) 
{
	Move plot_one=Move(1,2);//≥ı ºªØx=1,y=2 
	Move plot_two=Move(3,4);
	plot_one.showmove();
	plot_two.showmove();
	Move plot_four=plot_one.add(plot_two);
	plot_four.showmove();
	
	plot_one.reset(0,0);
	plot_one.showmove();
	return 0;
}
