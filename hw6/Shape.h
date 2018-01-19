#ifndef SHAPE_H
#define SHAPE_H
using namespace std;
#include <iostream>

class Shape
{
protected:
	int x;
	int y;
	string shapeName;
public:
	Shape()
	{
	}
	Shape(int centerX, int centerY,string name)
		:x(centerX),y(centerY),shapeName(name)
	{
	}
	virtual double area() = 0;
	virtual void draw()=0;
	virtual ~Shape()
	{

	}
};

#endif /* SHAPE_H */
