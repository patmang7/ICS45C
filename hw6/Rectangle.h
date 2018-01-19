#ifndef RECTANGLE_H
#define RECTANGLE_H
using namespace std;
#include <iostream>
#include "Square.h"

class Rectangle: public Square
{
protected:
	double side;
	double width;
public:
	Rectangle(int centerX,int centerY,string name,double s=0,double w=0)
		:Square(centerX,centerY,name,s),side(s),width(w)
	{
	}	

	virtual double area()
	{
		return side*width;
	}

	virtual void draw()
	{
		int i,p;
		for(i=0;i<width;i++)
		{
			for(p=0;p<side;p++)
				cout<<"*"<<flush;
			cout<<""<<endl;
		}
		cout<<""<<endl;		
	}

};
#endif
