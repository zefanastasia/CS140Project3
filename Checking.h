#pragma once

#include "Account.h"

class Checking : public Account{

public:
	Checking();
	Checking(const std::string& first, const std::string& last);
	virtual void display() const override;
	void withdraw(unsigned long long amt);
	unsigned int getOverdrawnCount() const;

protected:
	unsigned overdrawnCount{ 0 };



};