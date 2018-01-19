#ifndef CIRCLE_H
#define CIRCLE_H
using namespace std;
#include "Shape.h"

class Circle: public Shape
{
private:
	const double PI = 3.14159;
protected:
	double radius;
public:
	Circle(int centerX,int centerY,string name,double r=0)
		:Shape(centerX,centerY,name),radius(r)
	{
	}

	virtual double area()
	{
		return PI*radius*radius;
	}
	
	virtual void draw()
	{
		/*
		int i;
		for(i = 0;i<-2;i++)
			cout<<"*"<<flush;
		cout<<""<<endl;
		cout<<"   
		for(i = 0;i<radius-1;i++)
			cout<<"*"<<flush;
		cout<<""<<endl;
		for(i = 0;i<radius;i++)
			cout<<"*"<<flush;
		cout<<""<<endl;
		for(i = 0;i<radius-1;i++)
			cout<<"*"<<flush;
		cout<<""<<endl;
		for(i = 0;i<radius-2;i++)
			cout<<"*"<<flush;
		cout<<""<<endl;
		cout<<""<<endl;
		*/
		cout<<"        *****      "<<endl;
		cout<<"     ***********   "<<endl;
		cout<<"    *************  "<<endl;
		cout<<"  *****************"<<endl;
		cout<<"  *****************"<<endl;
		cout<<"  *****************"<<endl;
		cout<<"  *****************"<<endl;
		cout<<"    *************  "<<endl;
		cout<<"     ***********   "<<endl;
		cout<<"        *****      "<<endl;
		cout<<""<<endl;
	}
	
};

#endif	
