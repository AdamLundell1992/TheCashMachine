#include "CashMachineController.h"
#include<iostream>
#include<string>
using namespace std;
CashMachineController::CashMachineController() {
	balance = 0;
	pincode = 0000;
	bankAccountNumber = 000000;
	cardHolder = " ";
}
//defult constructor

CashMachineController::CashMachineController(int bankAccountNumber, std::string cardHolder, int pincode, double balance)
{
	this->bankAccountNumber = bankAccountNumber;
	this->cardHolder = cardHolder;
	this->pincode = pincode;
	this->balance = balance;
}
//overloading contructor

CashMachineController::~CashMachineController() {}
//destructor


int	CashMachineController::getBankAccountNumber() const
{
	std::cout << "Your current Bank account Number is : ";
	return bankAccountNumber;

}

int CashMachineController::getPincode()const
{

	return pincode;

}

std::string CashMachineController::viewCardHolder() const
{
	std::cout << "Your card is regisered on the name: ";
	return cardHolder;
}

double CashMachineController::checkBalance() const
{
	std::cout << "Your current Balance is :" << std::endl;
	return balance;
}

void CashMachineController::setBankAccountNumber(int& bankAccountNumber)
{
	bool failNumber;

	std::cout << "Enter a new Bank Accoount number 6 digits :" << std::endl;
	while (true) {

		do {
			std::cin >> bankAccountNumber;
			failNumber = std::cin.fail();
			if (failNumber) {
				std::cout << "Invalid input, try again with 6 digits: " << std::endl;// do this

			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (failNumber == true);
		if (!(bankAccountNumber < 99999) && !(bankAccountNumber > 1000000))
		{
			std::cout << "Valid -> " << std::endl;

			this->bankAccountNumber = bankAccountNumber;
			std::cout << "New Bank Account number is: " << bankAccountNumber << std::endl;
			break;
		}
		else
		{
			std::cout << "The number you have entered is not 6 digits please try again " << std::endl;
		}
	}
}

void CashMachineController::changeCardHolderName(std::string& cardHolder)
{

	bool valid;

	do {
		std::cout << "Enter a new name for your cardHolder :" << std::endl;

		std::cin >> cardHolder;
		valid = true;
		for (std::size_t i{}; i < cardHolder.length() && valid; ++i) {
			if (!(std::isalpha(static_cast<unsigned char>(cardHolder[i])) ||
				std::isspace(static_cast<unsigned char>(cardHolder[i])))) {
				valid = false;
				std::cout << "The name for the card holder need to be reffered as a alphabet" << std::endl;
			}
			else {
				std::cout << "Valid -> " << std::endl;
				std::cout << "New Name for the card holder is: " << cardHolder << std::endl;
				this->cardHolder = cardHolder;
				break;
			}
		}

	} while (!valid);
}


void CashMachineController::changePinCode(int& pincode)
{
	bool failNumber;
	std::cout << "Enter a new pincode, must be 4 digits :" << std::endl;
	while (true) {

		do {
			std::cin >> pincode;
			failNumber = std::cin.fail();
			if (failNumber) {
				std::cout << "Invalid input, try again with 4 valid digits: " << std::endl;// do this

			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (failNumber == true);
		if (!(pincode < 999) && !(pincode > 10000))
		{
			if (pincode == 0000)
				continue;
			std::cout << "Valid-> " << std::endl;

			this->pincode = pincode;
			std::cout << "New Pin code is: " << pincode << std::endl;
			break;
		}
		else
		{
			std::cout << "The number you have entered is not 4 digits please try again " << std::endl;
		}
	}
}

void CashMachineController::depositMoney(double& balance)
{

	bool failNumber;
	std::cout << "Enter your deposit value :" << std::endl;
	while (true) {

		do {
			std::cin >> balance;
			failNumber = std::cin.fail();
			if (failNumber) {
				std::cout << "Error-> Invalid input : " << std::endl;

			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		} while (failNumber == true);

		std::cout << "Valid-> " << std::endl;

		this->balance = balance;
		std::cout << "New balance is: " << balance << std::endl;
		break;
	}
}


void CashMachineController::withdrawMoney(double& balance, double& amount)
{
	bool failNumber;
	std::cout << "Enter your The amount of Money you need to withdraw from your bank account:" << std::endl;
	while (true) {

		do {
			std::cin >> amount;
			failNumber = std::cin.fail();
			if (failNumber) {
				std::cout << "Error-> Invalid input : " << std::endl;

			}


			
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin.clear();
		} while (failNumber == true);
		if (amount > this->balance) {
			std::cout << "You cannot credit this amount because your balance is to low " << std::endl;
		}
		else {
			std::cout << "Valid-> " << std::endl;

			double tempBalance = this->balance -= amount;

			std::cout << "New balance is: " << tempBalance << std::endl;
			break;
		}
	}
}

void CashMachineController::EnterCashMachine(CashMachineController& user, int& accPinCode) {
	bool failNumber;
	std::cout << "Put in you card " << std::endl;
	std::cout << ". . . .. .. . .. " << std::endl;
	do {
		while (true) {
			std::cout << "Enter your pin code: " << std::endl;
			std::cin >> accPinCode;
			failNumber = std::cin.fail();
			if (failNumber) {
				std::cout << "Invalid input, try again with 4 digits: " << std::endl;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			if (user.getPincode() == accPinCode)
			{
				std::cout << "Success-> You have entered the correct Pin code: double press enter to log in  " << std::endl;
				std::cout << ". . . .. .. . .. " << std::endl;
				break;
			}
			else {
				std::cout << "wrong pincode -> try again " << std::endl;
			}
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.clear();
	} while (failNumber == true);
}
void CashMachineController::createAccount(CashMachineController& user, int& accNum, std::string& accName, int& accPinCode) {
	std::cout << "You need a bank Account and a debit card to start " << std::endl;
	std::cout << "You will register and acces a card right now! " << std::endl;

	user.setBankAccountNumber(accNum);
	user.changeCardHolderName(accName);
	user.changePinCode(accPinCode);
	system("cls");
	std::cout << "Succesful registration -> " << std::endl;
	std::cout << "Here is your card sir -> Remember your pin code you selected " << std::endl; /*<< ">>" << user.getPincode() << "<<" << std::endl;*/
}
//functions