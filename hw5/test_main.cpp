#include <iostream>
using namespace std;
#include "String.h"

void test_constructor_and_print()
{
	String s("Patrick");
	String p("UCI rocks!");
	String m("Klefstad is dope!!");
	cout<<s<<endl;
	cout<<p<<endl;
	cout<<m<<endl;
}

void test_assignment()
{
	String s("Thomas");
	String p("Arnold");
	String c("Alexis");
	cout<<"s is "<<s<<endl;
	s = p;
	cout<<"s is "<<s<<endl;
	cout<<"p is "<<p<<endl;
	p = c;
	cout<<"p is "<<p<<endl;
	s = p;
	cout<<"s is "<<s<<endl;
}

void test_index()
{
	String s("Lamborghini");
	String c("Ferrari");
	char& p = s[3];
	char& m = s[0];
	char& y = c[4];
	cout<<"Fourth letter of "<<s<<" is "<<p<<endl;
	cout<<"First letter of "<<s<<" is "<<m<<endl;
	cout<<"Fifth letter of "<<c<<" is "<<y<<endl;
}

void test_equals()
{
	String s("Pizza");
	String c("Pizza");
	String m("Pizz");
	if(s==c)
		cout<<s<<" is equal to "<<c<<endl;
	else
		cout<<s<<" is not equal to "<<c<<endl;
	if(c==m)
		cout<<c<<" is equal to "<<m<<endl;
	else
		cout<<c<<" is not equal to "<<m<<endl;
}

void test_less_than()
{
	String c("Cat");
	String m("Cats");
	String d("A");
	if(c < m)
		cout<<c<<" is less than "<<m<<endl;
	
	if(m < d)
		cout<<m<<" is less than "<<d<<endl;
	else
		cout<<m<<" is not less than "<<d<<endl;
}

void test_add()
{
	String c("Hong Kong");
	String d(" phooey");
	String m("Vienna, ");
	String k("Austria");
	cout<<c<<endl;
	cout<<m<<endl;
	cout<<d<<endl;
	cout<<k<<endl;
	cout<<c+d<<endl;
	cout<<m+k<<endl;
}

void test_add_equals()
{
	String c("Bangkok ");
	String d("rush ");
	String m("hour.");
	String k("Gong hay ");
	String w("fat choy");
	cout<<c<<endl;
	cout<<k<<endl;
	c+=d;
	c+=m;
	k+=w;
	cout<<c<<endl;
	cout<<k<<endl;
}

void test_size()
{
	String c("Giraffe");
	String d("Elephant");
	String m("Snake");
	cout<<c<<" has size of "<<c.size()<<endl;
	cout<<d<<" has size of "<<d.size()<<endl;
	cout<<m<<" has size of "<<m.size()<<endl;	
}


void test_reverse()
{
	String c("Consecutive");
	String d("Subway");
	String m("Pizza is good");
	cout<<"The reverse of "<<c<<" is "<<c.reverse()<<endl;
	cout<<"The reverse of "<<d<<" is "<<d.reverse()<<endl;
	cout<<"The reverse of "<<m<<" is "<<m.reverse()<<endl;
}

void test_read()
{
	String c("Hi");
	String d("Bonjour");
	cout<<c<<endl;
	cout<<"Enter a test string: "<<endl;
	cin>>c;
	cout<<"String is now "<<c<<endl;
	cout<<d<<endl;
	cout<<"Enter a test string: "<<endl;
	cin>>d;
	cout<<"String is now "<<d<<endl;
}

void test_find_char()
{	
	String c("Spectre");
	String d("Sneaker");
	cout<<"Index of 'e' in "<<c<<" is "<<c.indexOf('e')<<endl;
	cout<<"Index of 'k' in "<<d<<" is "<<d.indexOf('k')<<endl;
}

int main()
{
	cout<<"------Testing Constructing and Printing------"<<endl;
	test_constructor_and_print();
	cout<<"------Testing Assignment------"<<endl;
	test_assignment();
	cout<<"------Testing Index------"<<endl;
	test_index();
	cout<<"------Testing Equals------"<<endl;
	test_equals();
	cout<<"------Testing Less Than------"<<endl;
	test_less_than();
	cout<<"------Testing Add------"<<endl;
	test_add();
	cout<<"------Testing Add Equals------"<<endl;
	test_add_equals();
	cout<<"------Testing Size------"<<endl;
	test_size();
	cout<<"------Testing Reverse------"<<endl;
	test_reverse();
	cout<<"------Testing Read------"<<endl;
	test_read();
	cout<<"------Testing Index of Char------"<<endl;
	test_find_char();
//	String::report_allocations();
	return 0;

}

