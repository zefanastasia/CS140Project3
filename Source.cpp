// Project 3

#include <iostream>
#include "Account.h"
#include "Checking.h"
#include "PremiumChecking.h"

using std::cout;
using std::endl;
using std::cin;

//Methods
void displaySelectionMenu();

int main()
{
	//Main loop, program runs until user terminates or selects the quit option
	unsigned selectionOperator{ 0 };
	while (selectionOperator != 5) 
	{
		displaySelectionMenu();
		cin >> selectionOperator;
		cout << endl;

		switch (selectionOperator) {
		case 1:
		case 2:
		case 3:
		case 4:
			cout << "TODO" << endl << endl;
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