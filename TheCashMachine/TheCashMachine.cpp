// TheCashMachine.cpp : This file contains the 'main' function. Program execution begins and ends there.

//Cash machine application
//Made by Adam Lundell

#include <iostream>
#include "CashMachineController.h"

int main()
{
    int accNum;
    std::string accName;
    int accPinCode;
    double amount;
    CashMachineController user;
    user.createAccount(user, accNum, accName, accPinCode);
    user.EnterCashMachine(user, accPinCode);
    while (true) {

        std::cout << "Your Options are:  " << std::endl;
        std::cout << "(1)-> deposit Money on your Bank Account " << std::endl;
        std::cout << "(2)-> credit money from your Bank Accoount " << std::endl;
        std::cout << "(3)-> change your account Card holder name " << std::endl;
        std::cout << "(4)-> change your pincode " << std::endl;
        std::cout << "(5)-> Se Account information" << std::endl;
        std::cout << "(0)-> Exit " << std::endl;
        int choice;
        std::cin >> choice;
        system("cls");
        switch (choice)
        {
        case 0:
        {
            std::cout << "Bank will now exit !" << std::endl;
            std::cout << "- - ------ -- -----" << std::endl;
            std::cout << "Remember to take your card " << std::endl;
            return 0;
        }
        case 1:
        {
            user.depositMoney(amount);
            break;
        }
        case 2:
        {
            double amountt;
            user.withdrawMoney(amount, amountt);
            break;
        }
        case 3:
        {
            user.changeCardHolderName(accName);
            break;
        }
        case 4:
        {
            user.changePinCode(accPinCode);
            break;
        }
        case 5:
        {

            std::cout << user.getBankAccountNumber() << std::endl;
            std::cout << user.viewCardHolder() << std::endl;
            std::cout << "Your Account pin code is: " << user.getPincode() << std::endl;
            std::cout << std::endl;
            std::cout << "Balance: " << user.checkBalance() << std::endl;
            break;
        }
        }



    }
}




