#ifndef PICTURE_H
#define PICTURE_H
using namespace std;
#include <iostream>
#include "Shape.h"

class Picture
{
public:
	Picture()
		:head(nullptr)
	{
	}

	void add(Shape* sp)
	{
		head = new ListNode(sp,head);
					
	}
	
	void drawAll()
	{
		ListNode* temp = head;
		if(temp != nullptr)
		{
			while(temp!=nullptr)
			{
				temp->info->draw();
				temp = temp->next;
			}
		}
	}

	double totalArea()
	{
		double total = 0;
		ListNode* temp = head;
		
		while(temp)
		{
			total += temp->info->area();
			temp = temp->next;

		}
		return total;
	}

	~Picture()
	{
		ListNode* temp;
		for(ListNode* m = head;m!=nullptr;)
		{
			temp = m;
			m = m->next;
			delete temp->info;
			delete temp;
		}
	}
private:
	struct ListNode
	{
		Shape* info;
		ListNode*next;
		ListNode(Shape* newInfo, ListNode*newNext)
			:info(newInfo),next(newNext)
		{
		}
	};
	ListNode* head;

};


#endif
