#ifndef _MOVE_H_
#define _MOVE_H_

class Move
{
private:
	double x;
	double y;
public:

Move(double a, double b);//sets x,y to a,b
	
~Move();//Îö¹¹º¯Êý 
	
showmove() const;//show current x,y values
	
Move add(const Move &m) const;

void reset(double a=0,double b=0);
};

#endif
