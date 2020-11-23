#include <iostream>
#include "Account.h"


unsigned int Account::accountTally{ 1 };

Account::Account()
{
	accountNumber = accountTally++;
}

Account::Account(const std::string& first, const std::string& last)
	: firstName{ first }, lastName{ last }
{
	accountNumber = accountTally++;
}

void Account::setFirstName(const std::string& first)
{
	firstName = first;
}

std::string Account::getFirstName() const
{
	return firstName;
}

void Account::setLastName(const std::string& last)
{
	lastName = last;
}

std::string Account::getLastName() const
{
	return lastName;
}

int Account::getAccountNumber() const
{
	return accountNumber;
}

unsigned long long Account::getBalance() const
{
	return balance;
}

void Account::display() const
{
	std::cout << "\nAccount details:" << std::endl;
	std::cout << "First name: " << getFirstName() << std::endl;
	std::cout << "Last name: " << getLastName() << std::endl;
	std::cout << "Account number: " << getAccountNumber() << std::endl;
	std::cout << "Balance: $" << (balance / 100) << "." << (balance % 100) << std::endl;
}

void Account::deposit(unsigned long long amt)
{
	if (amt > 0)
	{
		balance += amt;
	}
}

