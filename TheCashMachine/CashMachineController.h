#pragma once
#ifndef CASHMACHINE
#define CASHMACHINE
#include<iostream> 

class CashMachineController
{
public:

	CashMachineController();
	//defult constructor

	CashMachineController(int, std::string, int, double);
	//overloading constructor

	~CashMachineController();
	//destructor

	int	getBankAccountNumber() const;

	int getPincode()const;

	std::string viewCardHolder() const;

	double checkBalance() const;

	void setBankAccountNumber(int& bankAccountNumber);

	void changeCardHolderName(std::string& cardHolder);

	void changePinCode(int& pincode);

	void depositMoney(double& balance);

	void withdrawMoney(double& balance, double& amount);

	void createAccount(CashMachineController& user, int& accNum, std::string& accName, int& accPinCode);

	void EnterCashMachine(CashMachineController& user, int& accPinCode);
	//functions
private:
	int bankAccountNumber;
	std::string cardHolder;
	int pincode;
	double balance;
};

#endif // !CASHMACHINE