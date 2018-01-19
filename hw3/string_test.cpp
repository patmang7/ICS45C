using namespace std;
#include <iostream>
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

void test_not_equals()
{
	String s("Pasta");
	String c("Hot Dog");
	String m("Dim Sum");
	String k("Pasta");
	if(s!=c)
		cout<<s<<" is not equal to "<<c<<endl;
	else
		cout<<s<<" is equal to "<<c<<endl;
	
	if(c!=m)
		cout<<s<<" is not equal to "<<m<<endl;
	else
		cout<<s<<" is equal to "<<m<<endl;
	
	if(s!=k)
		cout<<s<<" is not equal to "<<k<<endl;
	else
		cout<<s<<" is equal to "<<k<<endl;
}

void test_greater_than()
{
	String c("Dog");
	String m("Doges");
	String d("Pat");
	String k("Patrick");
	if(m > c)
		cout<<m<<" is greater than "<<c<<endl;
	else
		cout<<m<<" is not greater than "<<c<<endl;
	if(d > k)
		cout<<d<<" is greater than "<<k<<endl;
	else
		cout<<d<<" is not greater than "<<k<<endl;
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

void test_greater_than_or_equal()
{
	String c("Horse");
	String d("Horse");
	String m("Horshoe");
	if(c >= d)
		cout<<c<<" is greater than or equal to "<<d<<endl;
	
	if(d >= m)
		cout<<d<<" is greater than or equal to "<<m<<endl;
	else
		cout<<d<<" is not greater than or equal to "<<m<<endl;
}

void test_less_than_or_equal()
{
	String c("Cows");
	String d("Cows");
	String m("Cow");
	if(c <= d)
		cout<<c<<" is less than or equal to "<<d<<endl;
	
	if(d <= m)
		cout<<d<<" is less than or equal to "<<m<<endl;
	else
		cout<<d<<" is not less than or equal to "<<m<<endl;
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
	cout<<"------Testing Not Equals------"<<endl;
	test_not_equals();
	cout<<"------Testing Greater Than------"<<endl;
	test_greater_than();
	cout<<"------Testing Less Than------"<<endl;
	test_less_than();
	cout<<"------Testing Greater Than or Equal To------"<<endl;
	test_greater_than_or_equal();
	cout<<"------Testing Less Than or Equal To------"<<endl;
	test_less_than_or_equal();
	cout<<"------Testing Add------"<<endl;
	test_add();
	cout<<"------Testing Add Equals------"<<endl;
	test_add_equals();
	cout<<"------Testing Size------"<<endl;
	test_size();
	return 0;

}

