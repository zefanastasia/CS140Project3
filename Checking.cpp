#include "Checking.h";
#include <iostream>


Checking::Checking()
{
	accountNumber = accountTally++;
}

Checking::Checking(const std::string& first, const std::string& last)
{
	firstName = first;
	lastName = last;
	accountNumber = accountTally++;
}

void Checking::withdraw(unsigned long long amt)
{
	if (amt <= 0) 
	{
		std::cout << "Error, a withdrawl requires a postive integer amount be inputted." << std::endl;
		return;
	}

	if (amt > balance)
	{
		//Informs the user there was an overdraw and informs the user how much money is in the balance, adds an overdraw penalty to account
		std::cout << "Error, not enough money in balance( " << balance << " ) "
			<< "to process withdraw( " << amt << " ) " << std::endl;
		++overdrawnCount;
		
		//Informs the user and overdraw penalty has been administered and for how much
		std::cout << "A overdrawn penalty has been administered for ";
		if (overdrawnCount < 3) 
		{ 
			std::cout << "10.00$";
			balance -= 10;
		}
		else 
		{
			std::cout << "30.00$"; 
			balance -= 30;
		}
		std::cout << std::endl;
		return;
	}

	balance -= amt;

}

unsigned int Checking::getOverdrawnCount() const
{
	return overdrawnCount;
}

void Checking::display() const
{
	Account::display();
	std::cout << "Overdraw Total: " << getOverdrawnCount() << std::endl;
}