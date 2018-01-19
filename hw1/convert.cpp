#include <iostream>
using namespace std;

double convert(int knot)
{
	double feet = knot*6076;
	double miles = feet/5280;
	return miles;	

}


int main()
{
	int input;
	cin >> input;
	double result = convert(input);
	cout<<result<<" miles per min\n";	
	return 0;
}


