#include <iostream>
using namespace std;
const int CENTS_PER_QUARTER = 25, CENTS_PER_DIME = 10, CENTS_PER_NICKEL = 5;

class Coins
{
public:
	
	Coins(int q, int d, int n, int p)
		:quarters(q),dimes(d),nickels(n),pennies(p)
	{
		numQuarters = quarters;
		numDimes = dimes;
		numNickels = nickels;
		numPennies = pennies;
		qq = 0;
		dd = 0;
		nn = 0;
		pp = 0;
	}

	void deposit_coins(Coins& c)
	{
 		this->quarters += c.quarters;
		this->dimes += c.dimes;
		this->nickels += c.nickels;
		this->pennies += c.pennies;
	}

	bool has_exact_change_for_cents(int amount_in_cents)
	{
		//cout<<amount_in_cents<<endl;
		if(amount_in_cents >= 25 && numQuarters != 0)
		{
			int num = amount_in_cents/CENTS_PER_QUARTER;
			if(numQuarters> num)
			{
				numQuarters = num;
			}
			int remaining = amount_in_cents-(numQuarters*CENTS_PER_QUARTER);
			numQuarters = 0;
			has_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents >= 10 && numDimes != 0)
		{
			int num = amount_in_cents/CENTS_PER_DIME;	
			if(numDimes > num)
			{
				numDimes = num;
			}
			int remaining = amount_in_cents-(numDimes*CENTS_PER_DIME);
			numDimes = 0;
			has_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents >= 5 && numNickels != 0)
		{
			int num = amount_in_cents/CENTS_PER_NICKEL;	
			if(numNickels > num)
			{
				numNickels = num;
			}
			int remaining = amount_in_cents-(numNickels*CENTS_PER_NICKEL);
			numNickels = 0;
			has_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents >= 1 && numPennies != 0)
		{
			int num = amount_in_cents;
			if(numPennies > num)
			{
				numPennies = num;
			}
			int remaining = amount_in_cents-numPennies;
			numPennies = 0;
			has_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents == 0)
		{	
			return true;
		}
		else
		{
			return false;
		}	
	}

	Coins extract_exact_change_for_cents(int amount_in_cents)
	{
		if(amount_in_cents >= 25 && quarters != 0)
		{
			int remaining = amount_in_cents - CENTS_PER_QUARTER;
			quarters--;
			extract_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents >= 10 && dimes != 0)
		{
			int remaining = amount_in_cents - CENTS_PER_DIME;
			dimes--;
			extract_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents >= 5 && nickels != 0)
		{
			int remaining = amount_in_cents - CENTS_PER_NICKEL;
			nickels--;
			extract_exact_change_for_cents(remaining);
		}
		else if(amount_in_cents >= 1 && pennies != 0)
		{
			int remaining = amount_in_cents - 1;
			pennies--;
			extract_exact_change_for_cents(remaining);
		}
		Coins result(numQuarters-quarters,numDimes-dimes,numNickels-nickels,numPennies-pennies);	      
		return result;
	}
	Coins get_coins(int amount_in_cents)
	{
		if(amount_in_cents >= 25)
		{
			int remaining = amount_in_cents - CENTS_PER_QUARTER;
			qq++;
			get_coins(remaining);
		}
		else if(amount_in_cents >= 10)
		{
			int remaining = amount_in_cents - CENTS_PER_DIME;
			dd++;
			get_coins(remaining);
		}
		else if(amount_in_cents >= 5)
		{
			int remaining = amount_in_cents - CENTS_PER_NICKEL;
			nn++;
			get_coins(remaining);
		}
		else if(amount_in_cents >= 1)
		{
			int remaining = amount_in_cents - 1;
			pp++;
			get_coins(remaining);
		}
		Coins result(qq,dd,nn,pp);
		return result;
	}
	void reset()
	{
		numQuarters = quarters;
		numDimes = dimes;
		numNickels = nickels;
		numPennies = pennies;
		qq = 0;
		dd = 0;
		nn = 0;
		pp = 0;
	}
		
	int total_value_in_cents()
	{
		return quarters*CENTS_PER_QUARTER+dimes*CENTS_PER_DIME+nickels*CENTS_PER_NICKEL+pennies;
	}
	void print(ostream& out)
	{
		out<<quarters<<" quarters, "<<dimes<<" dimes, "<<nickels<<" nickels, "<<pennies<<" pennies";
	}
private:
	int quarters, dimes, nickels, pennies;
	int numQuarters, numDimes, numNickels, numPennies;
	int qq,dd,nn,pp;
};

ostream& operator << (ostream& out, Coins c)
{
	c.print(out);
}



