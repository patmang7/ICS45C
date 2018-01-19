using namespace std;
#include <iostream>
#include "String.h"


char* String::strcpy(char*dest,const char*src)
{
	int i;	
	for(i=0;src[i] != '\0'&& i<MAXLEN-1;i++)
	{
		dest[i] = src[i];	
	}
	dest[i] = '\0';
	return dest;
}

int String::strcmp(const char* left, const char* right)
{
	int i;
	for(i = 0;right[i]!='\0' && i<MAXLEN-1;i++)
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
	int i,p=0;
	while(dest[p] != '\0')
		p++;

	for(i=0;src[i]!='\0'&&i<MAXLEN-1;i++)
	{
		dest[p] = src[i];
		p++;
	}
	dest[p] = '\0';
	return dest;			
}

int String::strlen(const char* s)
{
	int i,result=0;
	for(i=0;s[i]!='\0'&&i<MAXLEN-1;i++)
		result++;
	return result;
}

void String::print(ostream& out)
{
	out << buf;
}

void String::read(istream& in)
{
	in >> buf;
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

String::String(const char* s)
{
	strcpy(this->buf,s);
}

String::String(const String& s)
{
	
	strcpy(buf,s.buf);
}

String String::operator = (const String& s)
{
	String result(strcpy(this->buf,s.buf));
	return result;
}

char& String::operator [] (int index)
{
 	return this->buf[index];
}

bool String::operator == (const String s)
{
	return strcmp(this->buf,s.buf) == 0;
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
	String result(strcat(this->buf,s.buf));
	return result;
}

String String::operator += (const String s)
{
	String result(strcat(this->buf,s.buf));
	return result;
}

int String::size()
{
	return strlen(this->buf);
}

String::~String()
{
}

