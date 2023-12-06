// Developer: Zachariah Gannaway

// Assignment: Project 2

// Date of Submission: 22 November 2023

#include "InvestmentAccount.h"

//InvestmentAccount Implementation

InvestmentAccount::InvestmentAccount() {
	// Default Constructor
	m_initialDeposit = 0.00;
	m_monthlyDeposit = 0.00;
	m_percentInterest = 0.00;
	m_numberYears = 0;
}

InvestmentAccount::InvestmentAccount(double t_initialDeposit, double t_monthlyDeposit, double t_percentInterest, int t_numberYears) {
	// Constructor for when given arguments are passed through the creation of a class object.
	m_initialDeposit = t_initialDeposit;
	m_monthlyDeposit = t_monthlyDeposit;
	m_percentInterest = t_percentInterest;
	m_numberYears = t_numberYears;
}

// Getters for the class

double InvestmentAccount::getInitialDeposit() {
	return m_initialDeposit;
}

double InvestmentAccount::getMonthlyDeposit() {
	return m_monthlyDeposit;
}

double InvestmentAccount::getPercentInterest() {
	return m_percentInterest;
}

int InvestmentAccount::getNumberYears() {
	return m_numberYears;
}

// Setters for the class

void InvestmentAccount::setInitialDeposit(double t_initialDeposit) {
	m_initialDeposit = t_initialDeposit;
}

void InvestmentAccount::setMonthlyDeposit(double t_monthlyDeposit) {
	m_monthlyDeposit = t_monthlyDeposit;
}

void InvestmentAccount::setPercentInterest(double t_percentInterest) {
	m_percentInterest = t_percentInterest;
}

void InvestmentAccount::setNumberYears(int t_numberYears) {
	m_numberYears = t_numberYears;
}

void InvestmentAccount::getBalanceWithoutMonthlyDeposit(double t_initialDeposit, double t_percentInterest, int t_numberYears, double t_monthlyDeposit) {
	// Variable declaration 
	double closingBalance = m_initialDeposit;
	double interestPerMonth;
	double rate = m_percentInterest / 100 / 12;  // Given formula from Airgead Banking
	int i;
	int j;

	// Iterates for every year
	for (i = 0; i < m_numberYears; i++) {
		interestPerMonth = 0;   // Resets the interestPerMonth variable to 0 after each year
		// Iterates for each month of the year
		for (j = 0; j < 12; j++) {
			interestPerMonth += floor((closingBalance * rate) * 10000) / 10000;   // Rounds the interest per month down at the end of the calculation
			closingBalance += (closingBalance * rate);   // Increments the closing balance by the product of the previous closing balance and the rate.
		}
		// Displays the results for each year
		std::cout << i + 1 << std::fixed << std::setprecision(2) << std::setw(15) << "$" << closingBalance << std::setw(20) << "$" << interestPerMonth << std::endl << std::endl;
	}
}

void InvestmentAccount::getBalanceWithMonthlyDeposit(double t_initialDeposit, double t_percentInterest, int t_numberYears, double t_monthlyDeposit) {
	double closingBalance = t_initialDeposit;
	double interestPerMonth;
	double rate = t_percentInterest / 100 / 12;
	double interestEarned;
	double tempValue;
	int i;
	int j;


	// For loop that iterates for the first year 
	for (i = 0; i < 1; i++) {
		interestPerMonth = 0;
		for (j = 0; j < 12; j++) {
			interestPerMonth += floor((closingBalance * rate) * 10000) / 10000;
			closingBalance += t_monthlyDeposit;   // Increments closing balance with the monthly deposit
			closingBalance += (closingBalance * rate);  // Increments the closing balance with the interest earned
			
			// The first years interest earned is the difference in initial and ending balance and the total monthly deposits
			interestEarned = closingBalance - (t_monthlyDeposit * 12) - t_initialDeposit;  
		}
		tempValue = closingBalance;  // Temporarily holds the closing balance from year one

		// Displays the results from year one
		std::cout << i + 1 << std::fixed << std::setprecision(2) << std::setw(15) << "$" << closingBalance << std::setw(20) << "$" << interestEarned << std::endl << std::endl;
	}

	// For loop that iterates through the amount of years after year one (if needed)
	for (i = 1; i < t_numberYears; i++) {
		interestPerMonth = 0;
		for (j = 0; j < 12; j++) {
			interestPerMonth += floor((closingBalance * rate) * 10000) / 10000;
			closingBalance += t_monthlyDeposit;
			closingBalance += (closingBalance * rate);

			// Uses the tempValue to get the difference between closing balances between consecutive years
			interestEarned = closingBalance - (t_monthlyDeposit * 12) - tempValue;
		}
		tempValue = closingBalance;  // Reassigns the tempValue with the closing balance for that year

		// Displays the results for years after 1
		std::cout << i + 1 << std::fixed << std::setprecision(2) << std::setw(15) << "$" << closingBalance << std::setw(20) << "$" << interestEarned << std::endl << std::endl;
	}
}


void InvestmentAccount::printDetails() {

	// Displays the results from the user input
	// Displays the results with and without a monthly deposit
	// Formats into a table
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "  Balance and Interest Without Additional Monthly Deposits" << std::endl;
	std::cout << "============================================================" << std::endl;
	std::cout << "Year          Year End Balance      Year End Earned Interest" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	InvestmentAccount::getBalanceWithoutMonthlyDeposit(m_initialDeposit, m_percentInterest, m_numberYears, m_monthlyDeposit);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	std::cout << "  Balance and Interest With Additional Monthly Deposits" << std::endl;
	std::cout << "============================================================" << std::endl;
	std::cout << "Year          Year End Balance      Year End Earned Interest" << std::endl;
	std::cout << "------------------------------------------------------------" << std::endl;
	InvestmentAccount::getBalanceWithMonthlyDeposit(m_initialDeposit, m_percentInterest, m_numberYears, m_monthlyDeposit);
}

void InvestmentAccount::dataInput() {

	// THe input screen that proceeds the results page. Includes input validation for user entries.

	// Variable declaration
	std::string userString;
	bool inputFail = true;  // Used to loop until the input is within parameter boundaries
	int userInt;
	double userDouble;
	std::cout << "***********************************" << std::endl;
	std::cout << "************ Data Input ***********" << std::endl;
	std::cout << "Initial Investment Amount: $";
	std::cin >> userDouble;
	
	// Input validation ensuring that the initial investment is a positive number greater than 0.
	// Will produce an error message when input is out of boundary set
	// Prompts the user for re-entry if error
	// Once valid input is entered the loop breaks
	while (inputFail) {
		if (userDouble < 0) {
			std::cout << "Initial investment must be a positive number!" << std::endl;
			std::cout << "Initial Investment Amount: $";
			std::cin >> userDouble;
		}
		else {
			inputFail = false;

		}
	}
	InvestmentAccount::setInitialDeposit(userDouble);
	
	std::cout << "Monthly Deposit: $";
	std::cin >> userDouble;
	inputFail = true;  // Resets the boolean variable

	// Input validation ensuring that the monthly deposit is a positive number greater than 0.
	// Will produce an error message when input is out of boundary set
	// Prompts the user for re-entry if error
	// Once valid input is entered the loop breaks
	while (inputFail) {
		if (userDouble < 0) {
			std::cout << "Monthly deposit must be a positive number!" << std::endl;
			std::cout << "Monthly Deposit: $";
			std::cin >> userDouble;
		}
		else {
			inputFail = false;
		}
	}
	InvestmentAccount::setMonthlyDeposit(userDouble);
	
	
	std::cout << "Annual Interest: %";
	std::cin >> userDouble;
	inputFail = true;   // Resets the boolean variable

	// Input validation ensuring that the annual interest is a positive number greater than 0.
	// Will produce an error message when input is out of boundary set
	// Prompts the user for re-entry if error
	// Once valid input is entered the loop breaks
	while (inputFail) {
		if (userDouble < 0) {
			std::cout << "Annual interest must be a positive number!" << std::endl;
			std::cout << "Annual Interest: %";
			std::cin >> userDouble;
		}
		else {
			inputFail = false;
		}
	}
	InvestmentAccount::setPercentInterest(userDouble);

	
	std::cout << "Number of years: ";
	std::cin >> userInt;
	inputFail = true;   // Resets the boolean variable

	// Input validation ensuring that the number of years is a positive number greater than 0.
	// Will produce an error message when input is out of boundary set
	// Prompts the user for re-entry if error
	// Once valid input is entered the loop breaks
	while (inputFail) {
		if (userInt < 0) {
			std::cout << "Number of years must be a positive whole number!" << std::endl;
			std::cout << "Number of years: ";
			std::cin >> userInt;
		}
		else {
			inputFail = false;
		}
	}
	InvestmentAccount::setNumberYears(userInt);

	
	std::cout << "Press any key and enter to continue...";
	std::cin >> userString;
	std::cout << std::endl;
}