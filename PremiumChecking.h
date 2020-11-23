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
