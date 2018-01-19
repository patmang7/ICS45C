#ifndef TRIANGLE_H
#define TRIANGLE_H
using namespace std;
#include <iostream>
#include "Shape.h"

class Triangle: public Shape
{
protected:
	double base;
	double height;
public:
	Triangle(int centerX,int centerY,string name,double b=0, double h=0)
		:Shape(centerX,centerY,name), base(b), height(h)
	{
	}

	virtual double area()
	{
		return .5*base*height;	
	}
	
	virtual void draw()
	{
		int i = 1;
		while(i <= height)
		{
			int p;
			for(p=0;p<i;p++)
				cout<<"*"<<flush;
			cout<<""<<endl;				
			i++;
		}
		cout<<""<<endl;
	}	

};
#endif
