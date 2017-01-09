#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "BankSystem2.h"
#include <fstream>


//Bank Member Function definitions

void Bank::deposit(int x)
{
	m_deposit += x;
}

void Bank::withdrawl(int x)
{
	m_deposit -= x;
}

int Bank::returnBalance() const
{
	return m_deposit;
}

void Bank::showAccount() const 
{
	std::cout << "Account holder name: " << m_name << '\n';
	std::cout << "Balance: " << m_deposit << '\n';
	std::cout << "Account Number: " << m_accountNum << '\n';
	std::cout << "Account type (s/c): " << m_accountType << '\n';

}

void Bank::createAccount()
{
	std::cout << "Enter the account number " << std::endl;
	std::cin >> m_accountNum;
	std::cout << "Enter member name " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, m_name);
	std::cout << "Enter initital deposit: " << std::endl;
	std::cin >> m_deposit;
	std::cout << "Enter the account type: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, m_accountType);
}

void Bank::modify()
{
	std::cout << "Account Number: " << m_accountNum << std::endl;
	std::cout << "Modify name: " << std::endl;
	std::cin.ignore();
	std::getline(std::cin, m_name);
	std::cout << "Modify balance: " << std::endl;
	std::cin >> m_deposit;
	std::cout << "Modify account type: " << std::endl;
	std::cin.ignore();		
	std::getline(std::cin, m_accountType);

}

//Non member function definitions

void writeAccount(std::vector<Bank>& newly) 
{											
	Bank bankOne;
	bankOne.createAccount();
	newly.push_back(bankOne);


}

void modifyAccount(std::vector<Bank>& newly)
{
	int acc;
	bool check = false;
	std::cout << "What is the account number you would like to modify?" << std::endl;
	std::cin >> acc;
	for (auto i = 0; i != newly.size(); ++i) 
		if (newly[i].accountNumber() == acc)
		{
			newly[i].modify();
			check = true;
			break;
		}
	if (check = false)
		std::cout << acc << " is a invalid account number." << std::endl;
}

void deposit_withdrawl(std::vector<Bank>& newly)
{
	int acc;
	bool check = false;
	std::cout << "What is the account number you would like to modify? " << std::endl;
	std::cin >> acc;
	for (auto i = 0; i != newly.size(); ++i)
		if (newly[i].accountNumber() == acc)
		{
			check = true;
			int x;
			std::cout << "Would you like to deposit or withdrawl? (1 for deposit or 0 for withdrawl) " << std::endl;
			std::cin >> x;
			if (x == 1)
			{
				int amt;
				std::cout << "Transaction dollar amount: " << std::endl;
				std::cin >> amt;
				newly[i].deposit(amt);
				break;

			}
			if (x == 0)
			{
				int amt;
				std::cout << "Transaction dollar amount: " << std::endl;
				std::cin >> amt;
				newly[i].withdrawl(amt);
				break;

			}
			else
				std::cout << "You did not enter 0 or 1." << std::endl;
		}
	if (check = false)
		std::cout << acc << " is a invalid account number." << std::endl;

}

void displayAll(const std::vector<Bank>& newly)
{
	std::cout << "All accounts from specified container are listed displayed below: " << std::endl;
	for (auto i = 0; i != newly.size(); ++i)
		newly[i].showAccount();
}

// Make friend so that we can access the member variables
void deleteAccount(std::vector<Bank>& newly)
{
	//Removing elements anywhere but the beginning or end in a vector causes iterators, references and pointers after
	//the erasure point to be invalidated
	// Therefore, rather than actually remove the element I will set all data members to a default value

	int acc;
	bool check = false;
	std::cout << "What is the account that you would like to remove?" << std::endl;
	std::cin >> acc;

	for (auto i = 0; i != newly.size(); ++i)
		if (newly[i].accountNumber() == acc)
		{
			newly[i].m_accountNum = 0;
			newly[i].m_accountType = " ";
			newly[i].m_name = "DELETED";
			newly[i].m_deposit = 0;
			check = true;
			break;
		}
	if (check = false)
		std::cout << "You entered a invalid account number." << std::endl;
}

void displayAccount(const std::vector<Bank>& newly)
{
	int acc;
	bool check = false;
	std::cout << "What account would you like to display? " << std::endl;
	std::cin >> acc;

	for (auto i = 0; i != newly.size(); ++i)
		if (newly[i].accountNumber() == acc)
		{
			newly[i].showAccount();
			check = true;
			break;
		}
	if (check = false)
		std::cout << "You entered a invalid account number." << std::endl;
}

// Make friend so that we can access the member variables
void saveAccount(std::vector<Bank>& newly) 
{
	std::ofstream outFile;
	outFile.open("bankData.txt", std::ofstream::app); 

	for (int i = 0; i != newly.size(); i++)
	{
		outFile << "Record: ";
		outFile << newly[i].m_accountNum << "," << newly[i].m_name << "," << newly[i].m_deposit << ","
			<< newly[i].m_accountType << std::endl;
	}
}
