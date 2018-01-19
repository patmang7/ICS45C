#include <iostream>
using namespace std;
#include "Coins.h"

const int CENTS_FOR_CHIPS = 68;
int main()
{
	Coins pocket(5,3,6,8);
	Coins piggyBank(50,50,50,50);
	cout<<"I started with "<<pocket<<" in my pocket and "<<piggyBank<<" in my piggy bank"<<endl;
	Coins payForChips = pocket.extract_exact_change_for_cents(CENTS_FOR_CHIPS);
	cout<<"I bought a bag of chips using "<<payForChips<<endl;
	cout<<"I have "<<pocket<<" left in my pocket."<<endl;
	Coins transfer = piggyBank.extract_exact_change_for_cents(205);
	pocket.deposit_coins(transfer);
	cout<<"I transfered "<<transfer<<" to my pocket."<<endl;
	cout<<"I now have "<<pocket<<" in my pocket."<<endl;
	cout<<"I have "<<piggyBank<<" left in my piggy bank."<<endl;
	Coins loose(10,10,10,10);
	piggyBank.deposit_coins(loose);
	double value = piggyBank.total_value_in_cents()/100.0;
	cout<<"I found "<<loose<<". I know have $"<<value<<" in my piggy bank."<<endl;
	return 0;
}
