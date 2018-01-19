#include "Picture.h"
#include "Shape.h"
#include "Triangle.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include <iostream>
using namespace std;

int main()
{
	Picture p;
	Triangle* t1 = new Triangle(0,0,"t1",5,5);
	Triangle* t2 = new Triangle(0,0,"t2",3,4);
	p.add(t1);
	p.add(t2);
	Circle* c1 = new Circle(0,0,"c1",5);
	Circle* c2 = new Circle(0,0,"c2",10);
	p.add(c1);
	p.add(c2);
	Square* s1 = new Square(0,0,"s1",5);
	Square* s2 = new Square(0,0,"s2",10);
	p.add(s1);
	p.add(s2);
	Rectangle* r1 = new Rectangle(0,0,"r1",4,8);
	Rectangle* r2 = new Rectangle(0,0,"r2",8,4);
	p.add(r1);
	p.add(r2);
	p.drawAll();
	double total = p.totalArea();
	cout<<"Total area of shapes is: "<<total<<" square units"<<endl;
	return 0;
}

