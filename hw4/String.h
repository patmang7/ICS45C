using namespace std;
#include <iostream>

class String
{
public:
	String(const char* s = "");
	String(const String& s);
	String operator = (const String& s);
	char& operator[](int index);
	int size();
	String reverse();
	int indexOf(const char c);
	int indexOf(const String pattern);
	bool operator == (const String s);
	bool operator != (const String s);
	bool operator > (const String s);
	bool operator < (const String s);
	bool operator <= (const String s);
	bool operator >= (const String s);
	String operator + (const String s);
	String operator += (const String s);
	void print(ostream& out);
	void read(istream& in);
	~String();
	static void report_allocations()
	{
		if(allocations>0)
			error("Memory leak");
		if(allocations<0)
			error("Too many delete[]s");
		if(allocations == 0)
			cout<<"Number of new allocations minus number of delete allocations is 0\n";
	}
private:
	bool inBound(int i)
	{
		return i >=0 && i<strlen(buf);
	}
	static int strlen(const char* s);
	static char *strdup(const char *src);
	static char* strcpy(char* dest, const char* src);
	static char* strcat(char* dest, const char* src);
	static int strcmp(const char* left, const char* right);
	static int strncmp(const char* left, const char* right, int n);
	static const char* strchr(const char* str, int c);
	static char* strchr(char* str, int c);
	static const char* strstr(const char* haystack, const char* needle);
	char* buf;
	static int allocations;
	static void error(const char* p)
	{
		cout<<"Error: " <<p<<endl;
	}
	static char* new_char_array(int n_bytes)
	{
		++allocations;
		return new char[n_bytes];
	}

	static void delete_char_array(char* p)
	{
		--allocations;
		if(allocations<0)
			error("more delete[] than new[]");
		else
			delete[] p;	
	}

};
ostream& operator<<(ostream& out, String str);
istream& operator>>(istream& in, String& str);

	
