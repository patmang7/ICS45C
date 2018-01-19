#include "Coins.h"
#include <iostream>
using namespace std;

const int CENTS_FOR_CANDYBAR = 482;
int main()
{

	Coins pocket(100,10,10,100);
	cout << "I started with "<<pocket<<" in my pocket"<<endl;
	Coins payForCandy = pocket.extract_exact_change_for_cents(CENTS_FOR_CANDYBAR);
	cout<<"I bought a candy bar for "<<CENTS_FOR_CANDYBAR<<" cents using "<<payForCandy<<endl;
	cout<<"I have "<<pocket<<" left in my pocket" << endl;
//	Coins pocket(2,2,0,2);
//	cout<<pocket.has_exact_change_for_cents(30)<<endl;
	return 0;
}
	
