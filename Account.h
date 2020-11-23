#pragma once

#include <string>

class Account
{
public:
	Account();
	Account(const std::string& first, const std::string& last);
	void setFirstName(const std::string& first);
	std::string getFirstName() const;
	void setLastName(const std::string& last);
	std::string getLastName() const;
	int getAccountNumber() const;
	unsigned long long getBalance() const;
	void deposit(unsigned long long amt);
	virtual void display() const;

protected:
	std::string firstName;
	std::string lastName;
	static unsigned int accountTally;
	unsigned int accountNumber;
	unsigned long long balance{ 0ULL };
};