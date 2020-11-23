#include "PremiumChecking.h"
#include <iostream>

PremiumChecking::PremiumChecking()
{
	accountNumber = accountTally++;
}

PremiumChecking::PremiumChecking(const std::string& first, const std::string& last)
{
	firstName = first;
	lastName = last;
	accountNumber = accountTally++;
}

void PremiumChecking::chargeMonthlyFee()
{
	this->balance -= monthlyFee;
}

unsigned long long PremiumChecking::getMonthlyFee() const
{
	return monthlyFee;
}

void PremiumChecking::setMonthlyFee(unsigned long long mf)
{
	this->monthlyFee = mf;
}


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

void PremiumChecking::display() const
{
	Account::display();
	std::cout << "Monthly Fee: $" << (monthlyFee / 100) << "." << (monthlyFee % 100) << std::endl;
}