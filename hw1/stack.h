#define STACK_CAPACITY 1000
#include <iostream>
using namespace std;
class Stack
{
public:
	int count = 0;
	char stack[STACK_CAPACITY];
	Stack()
	{
					
	}

	void push(char c)
	{
		if(isFull())
		{
			error("Cannot push on full stack");
			return;
		}
		stack[count] = c;
		count++;
	}

	char pop()
	{
		if(isEmpty())
		{
			error("Cannot pop from empty stack");
		}
		else
		{
			char top = stack[count-1];
			count--;
			return top;
		}
	}
	
	char top()
	{
		return stack[count];
	}

	bool isEmpty()
	{
		return count <= 0;
	}

	bool isFull()
	{
		return count >= STACK_CAPACITY-1;
	}

	~Stack()
	{
	}
private:
	void error(const char* msg)
	{
		cout<<"ERROR "<<msg<<"\n";
	}
};

	
	 		
