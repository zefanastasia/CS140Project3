//Represents a bank premium checking account and allows the user to withdraw money from the account but costs a monthly fee
//The user is allowed to overdraw from the account but only up to 200$, no overdraw penalties occur for overdrawing
#pragma once

#include "Account.h"

class PremiumChecking : public Account
{
public:
	PremiumChecking();
	PremiumChecking(const std::string& first, const std::string& last);
	void chargeMonthlyFee();
	unsigned long long getMonthlyFee() const;
	void setMonthlyFee(unsigned long long mf);
	void withdraw(unsigned long long amt);
	virtual void display() const override;

protected:
	unsigned long long monthlyFee{ 575ULL };





};
