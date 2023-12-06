// Developer: Zachariah Gannaway

// Assignment: Project 2

// Date of Submission: 22 November 2023

#include "InvestmentAccount.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {

	// Variable declaration
	string userChoice;
	bool quit = false;

	// While loop that will continue until user writes "quit"
	// This loop displays input menu then the results and then prompts user input to continue
	while(!quit) {
		InvestmentAccount myAccount;
		myAccount.dataInput();
		myAccount.printDetails();
		cout << "Press any key to continue or type \"quit\" to end session." << endl;
		cin >> userChoice;
		if (userChoice == "quit") {
			quit = true;
		}
	}
	
	

	return 1;
}