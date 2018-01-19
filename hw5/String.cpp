#include <iostream>
using namespace std;
#include "String.h"

String::ListNode* String::ListNode::stringToList(const char* s)
{
	if(s==nullptr || *s=='\0')
		return  nullptr;
	ListNode* n = new ListNode(s[0],nullptr);
	ListNode* tempHead = n;
	int i;
	for(i = 1;s[i]!='\0';i++)
	{
		n->next = new ListNode(s[i],nullptr);
		n = n->next;
	}
	return tempHead;
}

String::ListNode* String::ListNode::copy(ListNode* L)
{
	return L==nullptr?nullptr: new ListNode(L->info,copy(L->next));
}

String::ListNode* String::ListNode::reverse(ListNode* L, ListNode* R)
{
	ListNode* result = nullptr;
	ListNode* m = L;
	while(m != nullptr)
	{
		result = new ListNode(m->info,result);
		m = m->next;
	}
	return result;
}

String::ListNode* String::ListNode::append(ListNode* L1,ListNode* L2)
{
	return L1 == nullptr? copy(L2):new ListNode(L1->info,append(L1->next,L2));
}

int String::ListNode::compare(ListNode* L1, ListNode* L2)
{
	ListNode* temp1 = L1;
	ListNode* temp2 = L2;
	if(temp1 == nullptr)
		return -1;
	if(temp2 == nullptr)
		return 1;
	while(temp1->next!=nullptr&&temp2->next!=nullptr)
	{
		if(temp1->info!=temp2->info)
			return temp1->info-temp2->info;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	if(temp1->next!=nullptr)
		return 1;
	if(temp2->next!=nullptr)
		return -1;
	return temp1->info-temp2->info;
}

void String::ListNode::deleteList(ListNode* L)
{
	ListNode* temp;
	ListNode* m = L;
	while(m!=nullptr)
	{
		temp = m;
		m = m->next;
		delete temp;
	}
}

int String::ListNode::length(ListNode* L)
{
	int i;
	ListNode* temp = L;
	for(i = 0;temp!=nullptr;i++)
		temp  = temp->next;
	return i;
}

String::String(const char* s)
{
	this->head = ListNode::stringToList(s);
}

String::String(const String& s)
{	
	this->head = ListNode::copy(s.head);		
}

String String::operator = (const String& s)
{
	ListNode* temp = ListNode::copy(s.head);
	ListNode::deleteList(this->head);
	this->head = temp;
	return *this;
}

char& String::operator [] (const int index)
{
	if(!inBounds(index))
		return this->head->info;
	int i;
	ListNode* temp = this->head;
	for(int i = 0;i<index;i++)
		temp = temp->next;
	return temp->info;
}

int String::size()
{
	return ListNode::length(this->head);
}

int String::indexOf(char c) const
{
	int i;
	ListNode* temp = this->head;
	for(i=0;temp!=nullptr;i++)
	{
		if(temp->info == c)
			return i;
		temp = temp->next;
	}
	return -1;
}

bool String::operator == (const String& s) const
{
	return ListNode::compare(this->head,s.head) == 0;
}

bool String::operator < (const String& s) const
{
	return ListNode::compare(this->head,s.head) < 0;
}

String String::operator + (const String& s) const
{
	String result;
	result.head = ListNode::append(this->head,s.head);	
	return result;
}

String String::operator += (const String& s)
{
	ListNode* temp = ListNode::append(this->head,s.head);
	ListNode::deleteList(this->head);
	this->head = temp;
	return *this;
}

String String::reverse() const
{
	ListNode* temp = ListNode::reverse(this->head);
	String result;
	result.head = temp;
	//ListNode::deleteList(temp);
	return result;
}

void String::print(ostream& out) const
{
	int i;
	ListNode* temp = head;
	while(temp != nullptr)
	{
		out<<temp->info;
		temp = temp->next;
	}
}

ostream& operator << (ostream& out, String str)
{
	str.print(out);
	return out;
}
istream& operator >> (istream& in,String& str)
{
	str.read(in);
	return in;
}

void String::read(istream& in)
{
	char result[1024];
	in.getline(result,1024);
	ListNode::deleteList(this->head);
	this->head = ListNode::stringToList(result);		
}

String::~String()
{
	ListNode::deleteList(this->head);
}




































