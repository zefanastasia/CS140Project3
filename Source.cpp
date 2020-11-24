// Project 3

#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <random>
#include "Account.h"
#include "Checking.h"
#include "PremiumChecking.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::string;
using std::default_random_engine;
using std::uniform_int_distribution;

//Methods
void displaySelectionMenu();
string randomName(default_random_engine&, const vector<string>&);
void genCheckingAccounts(int, vector<Account*>&, default_random_engine&, const vector<string>&, const vector<string>&);
void genPremiumCheckingAccounts(int, vector<Account*>&, default_random_engine&, const vector<string>&, const vector<string>&);
void displayAccounts(const vector<Account*>&);

int main()
{
	vector<string> fnames = 
	{
		"Matt", "Clark", "Cindy", "Joe", "Aasav", "Aaron", "Samantha", "Beth", "Bart"
	};

	vector<string> lnames =
	{
		"Smith", "Johnson", "Kent", "Liftman", "Crownings", "Backers", "Stone", "Powers"
	};

	vector<Account*> accRegistry{};

	//Instanciate random integer engine
	default_random_engine engine{ static_cast<unsigned int>(time(0)) };


	//Main loop, program runs until user terminates or selects the quit option
	unsigned selectionOperator{ 0 };
	while (selectionOperator != 5) 
	{
		displaySelectionMenu();
		cin >> selectionOperator;
		cout << ""<<endl;

		int numAcc;

		switch (selectionOperator) {
		case 1:
			cout << "How many checking accounts would you like to create? ";
			cin >> numAcc;
			genCheckingAccounts(numAcc, accRegistry, engine, fnames, lnames);
			break;
		case 2:
			cout << "How many premium checking accounts would you like to create? ";
			cin >> numAcc;
			genPremiumCheckingAccounts(numAcc, accRegistry, engine, fnames, lnames);
			break;
		case 3:
			cout << "TODO" << endl << endl;
			break;
		case 4:
			displayAccounts(accRegistry);
			break;
		case 5:
			cout << "Exiting Program..." << endl;
			break;
		default:
			cout << "Please select a valid option(1-5)." << endl << endl;
		}



	}
}

void displaySelectionMenu()
{
	cout << "MENU: \n"
		<< "1. Create Checking accounts\n"
		<< "2. Create Premium accounts\n"
		<< "3. Create Savings accounts(TODO)\n"
		<< "4. Display all accounts\n"
		<< "5. Quit\n"
		<< "Selection : ";
}

string randomName(default_random_engine& engine, const vector<string>& names)
{
	uniform_int_distribution<unsigned int> randomInt{ 0, names.size() - 1};
	unsigned selection = randomInt(engine);
	return names[selection];
}

void genCheckingAccounts(int numAcc, vector<Account*>& accList, default_random_engine& engine, const vector<string>& fnames, const vector<string>& lnames)
{
	uniform_int_distribution<unsigned long long> randomULL(1000, 92233720);
	for (int index = 0; index < numAcc; index++)
	{
		Account* tempAcc = new Checking(randomName(engine, fnames), randomName(engine, lnames));
		tempAcc->deposit(randomULL(engine));
		tempAcc->display();
		accList.push_back(tempAcc);
	}
}

void genPremiumCheckingAccounts(int numAcc, vector<Account*>& accList, default_random_engine& engine, const vector<string>& fnames, const vector<string>& lnames)
{
	uniform_int_distribution<unsigned long long> randomULL(1000, 92233720);
	for (int index = 0; index < numAcc; index++)
	{
		Account* tempAcc = new PremiumChecking(randomName(engine, fnames), randomName(engine, lnames));
		tempAcc->deposit(randomULL(engine));
		tempAcc->display();
		accList.push_back(tempAcc);
	}
}

void displayAccounts(const vector<Account*>& accList)
{
	for (unsigned index = 0; index < accList.size(); index++)
	{
		accList.at(index)->display();
	}
}