#include <iostream>
using namespace std;
#include "Coins.h"

int main()
{
	Coins myCoins(0,0,0,0);
	char input = 'm';
	while(input != 'n')
	{
		cout<<"Welcome to the Bank of UCI"<<endl;
		cout<<"Please select from the following options below:"<<endl;
		cout<<"Type d to deposit change"<<endl;
		cout<<"Type e to extract change"<<endl;
		cout<<"Type p to print the current balance in your account"<<endl;
		cout<<"Type q to exit from the atm"<<endl;
		cin >> input;
		switch(input)
		{
			case 'd':
				{
					cout<<"Enter amount to deposit in cents:"<<endl;
					int d;
					cin >> d;
					Coins deposit = myCoins.get_coins(d);
					myCoins.deposit_coins(deposit);
					myCoins.reset();
					break;
				}
			case 'e':
				{
					cout<<"Enter amount to extract in cents:"<<endl;
					int e;
					cin >> e;
					if(myCoins.has_exact_change_for_cents(e))
					{
						Coins extract = myCoins.extract_exact_change_for_cents(e);
						myCoins.reset();
					}
					else
					{
						cout<<"Sory, you do not have sufficient funds in your account"<<endl;						      myCoins.reset();	
					}
					break;
				}
			case 'p':
				{
					cout<<"You currently have "<<myCoins<<" in your account"<<endl;
					break;
				}
			case 'q':
				break;	
			default:
				cout<<"Invalid operation"<<endl;
				break;
		}
		if (input!='q')
		{
			cout<<"Do you want to perform further operations?(Enter y or n)"<<endl;
			cin>>input;
		}
		else if(input == 'q')
		{
			break;
		}
	}
	return 0;
}

