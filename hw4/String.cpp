#define MAX_READ_SIZE 1024
using namespace std;
#include <iostream>
#include <cstddef>
#include "String.h"

int String::allocations = 0;

char* String::strdup(const char* src)
{
	char* result = new_char_array(strlen(src)+1);
	int i;
	for(i=0;src[i]!= '\0';i++)
		result[i] = src[i];
	result[i] = '\0';
	return result;
	
}

int String::strcmp(const char* left, const char* right)
{
	int i;
	for(i = 0;right[i]!='\0';i++)
	{
		if(left[i] != right[i])
			return left[i]-right[i];
	}
	if(left[i]!='\0')
		return int(left[i]);
	return 0;
}

int String::strncmp(const char* left, const char* right, int n)
{
	int i;
	for(i = 0;i<n;i++)
	{
		if(left[i] != right[i])
			return left[i]-right[i];
	}

	return 0;
}

char* String::strcat(char* dest, const char* src)
{
	char* result = new_char_array(strlen(dest)+strlen(src)+1);
	int i,p = 0;
	for(i=0;dest[i]!='\0';i++)
	{
		result[i] = dest[i];
		p++;
	}
	int m;
	for(m=p;src[m-p]!='\0';m++)
		result[m] = src[m-p];
	result[m] = '\0';
	return result; 			
}

int String::strlen(const char* s)
{
	int i,result=0;
	for(i=0;s[i]!='\0';i++)
		result++;
	return result;
}

const char* String::strchr(const char* str, int c)
{
	int i=0;
	char* result = 0;
	while(str[i]!='\0')
	{
		if(str[i]==char(c))
		{
			*result = str[i];
			return result;
		}
		i++;
	}
	if(c == '\0')
	{
		*result = str[i];
		return result;
	}
	return result;	
}

String::String(const char* s)
{
	this->buf = strdup(s);
}

String::String(const String& s)
{
	
	this->buf = strdup(s.buf);
}

String String::operator = (const String& s)
{
	char* h = strdup(s.buf);
	delete_char_array(this->buf);
	this->buf = h;
	return *this;
}

char& String::operator [] (int index)
{
 
	return this->buf[index];
}

bool String::operator == (const String s)
{
	return strcmp(this->buf,s.buf) == 0;
}

void String::print(ostream& out)
{
	out << buf;
}

void String::read(istream& in)
{
	char* read_array = new_char_array(MAX_READ_SIZE);
	in.getline(read_array, MAX_READ_SIZE);
	delete_char_array(this->buf);
	this->buf = strdup(read_array);
	delete_char_array(read_array);
}

ostream& operator << (ostream& out, String str)
{
	str.print(out);
	return out;
}

istream& operator >> (istream& in, String& str)
{
	str.read(in);
	return in;	
}

bool String::operator != (const String s)
{
	return strcmp(this->buf,s.buf) != 0;
}

bool String::operator > (const String s)
{
	return strcmp(this->buf,s.buf) > 0;
}

bool String::operator < (const String s)
{
	return strcmp(this->buf,s.buf) < 0;	
}	

bool String::operator >= (const String s)
{
	return strcmp(this->buf,s.buf) > 0 || strcmp(this->buf,s.buf) == 0;
}

bool String::operator <= (const String s)
{
	return strcmp(this->buf,s.buf) < 0 || strcmp(this->buf,s.buf) == 0;
}

String String::operator + (const String s)
{
	char* h = strcat(this->buf,s.buf);
	delete_char_array(this->buf);
	this->buf = h;
	return *this;
}

String String::operator += (const String s)
{
	char* h = strcat(this->buf,s.buf);
	delete_char_array(this->buf);
	this->buf = h;
	return *this;
}

int String::size()
{
	return strlen(this->buf);
}
	
String String::reverse()
{
	char* result = new_char_array(strlen(this->buf)+1);
	int i,p=0;
	for(i=size()-1;i>=0;i--)
	{
		result[p]=this->buf[i];
		p++;	
	}
	result[p] = '\0';
	delete_char_array(this->buf);
	this->buf = result;
	return *this;
}

//int String::indexOf(const char c)
//{
//	char* result = strchr(this->buf,c);
//	int i = 0;
//	while(this->buf[i] != result)
//		i++;
//	return i;
//}


String::~String()
{
	delete_char_array(this->buf);
}

