#ifndef SQUARE_H
#define SQUARE_H
using namespace std;
#include <iostream>
#include "Shape.h"

class Square: public Shape
{
protected:
	double side;
public:
	Square(int centerX,int centerY, string name, double s=0)
		:Shape(centerX,centerY,name), side(s)
	{
	}

	virtual double area()
	{
		return side*side;
	}

	virtual void draw()
	{
		int i,p;
		for(i=0;i<side;i++)
		{
			for(p=0;p<side;p++)
				cout<<"* "<<flush;
			cout<<""<<endl;
		}	
		cout<<""<<endl;
	}
	
	
};
#endif
