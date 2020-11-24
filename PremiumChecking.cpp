#include "PremiumChecking.h"
#include <iostream>

//Default Construtor
PremiumChecking::PremiumChecking()
{
}
//Constructor sets the first and last names of the account
PremiumChecking::PremiumChecking(const std::string& first, const std::string& last)
{
	firstName = first;
	lastName = last;
}

//Subtracts a fee from the users account based on the monthly fee amount
void PremiumChecking::chargeMonthlyFee()
{
	this->balance -= monthlyFee;
}

//Getter for the accounts monthly fee
unsigned long long PremiumChecking::getMonthlyFee() const
{
	return monthlyFee;
}

//Setter for the accounts monthly fee
void PremiumChecking::setMonthlyFee(unsigned long long mf)
{
	this->monthlyFee = mf;
}

//Withdraws money from the account balance up to 200.00$ more than the balance total
//If the overdraw is over $200.00 the transaction will be cancelled but no overdraw fees will occur
void PremiumChecking::withdraw(unsigned long long amt)
{
	if (amt <= 0)
	{
		std::cout << "Error, a withdrawl requires a postive integer amount be inputted." << std::endl;
		return;
	}

	unsigned long long newBalance = balance - amt;

	if (newBalance < -20000)
	{
		std::cout << "Error, not enough money in the account to withdraw the amount.\n"
			<< "Overdraw amount: $" << ( (-1 * newBalance) / 100) << "." << ( (-1 * newBalance) % 100) << std::endl;
		return;
	}

	balance = newBalance;

}

//Displays the info of the premium checking account
void PremiumChecking::display() const
{
	Account::display();
	std::cout << "Monthly Fee: $" << (monthlyFee / 100) << "." << (monthlyFee % 100) << std::endl;
}