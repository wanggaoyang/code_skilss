#ifndef XIGOU_H
#define XIGOU_H

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual double calcAera();
};

class Coordinate 
{
public:
	Coordinate(int x,int y);
	virtual ~Coordinate();
private:
	int m_iX;
	int m_iY;
};

class Circle :public Shape
{
public:
	Circle(double r);
	virtual ~Circle();
	virtual double calcAera();
protected:
	double m_dR;
	Coordinate *m_pCenter;
};




#endif
