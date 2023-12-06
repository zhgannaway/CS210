// Developer: Zachariah Gannaway

// Assignment: Project 2

// Date of Submission: 22 November 2023

#pragma once
#ifndef CS210PROJECT2_INVESTMENTACCOUNT_H_
#define CS210PROJECT2_INVESTMENTACCOUNT_H_


#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>

class InvestmentAccount
{

public:
	// Constructors
	InvestmentAccount();
	InvestmentAccount(double t_initialDeposit, double t_monthlyDeposit, double t_percentInterest, int t_numberYears);

	// Calculate the balance details without the monthly deposit
	void getBalanceWithoutMonthlyDeposit(double t_initialDeposit, double t_percentInterest, int numberYears, double t_monthlyDeposit);   
	
	// Calculate the balance details with the monthly deposit
	void getBalanceWithMonthlyDeposit(double t_initialDeposit, double t_percentInterest, int numberYears, double t_monthlyDeposit);

	// Getters
	double getInitialDeposit();
	double getMonthlyDeposit();
	double getPercentInterest();
	int getNumberYears();

	// Setters
	void setInitialDeposit(double);
	void setMonthlyDeposit(double);
	void setPercentInterest(double);
	void setNumberYears(int);

	// Display
	void printDetails();
	void dataInput();

private:
	double m_initialDeposit;
	double m_monthlyDeposit;
	double m_percentInterest;
	int m_numberYears;


};

#endif 