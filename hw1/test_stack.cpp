#include "stack.h"
using namespace std;
#include <iostream>

int main()
{
	
	string str = "";
	while(str != "^D")
	{
		getline(cin,str);
		Stack* stack = new Stack();
		for(int i = 0;i<str.size();i++)
		{
			stack->push(str[i]);
		}	

		for(int p = 0;p<str.size();p++)
		{	
			char popped = stack->pop();
			cout<<popped;
		}
		cout<<"\n";
	}
	return 0;
	
}
