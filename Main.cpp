//By: Joe Grazewski 
//Bank System
//This is a banking system program. It lets you create and manage new accounts. The file stores all objects in a 
//vector. The program also allows you to save the objects into a text file. If I wanted to take this project 
//one step further I would use ifstream and stringstream to load in data then append it. 


#include "stdafx.h"
#include <iostream>
#include <string>
#include "BankSystem2.h"
#include <vector>
#include <fstream>


int main()
{
	

	std::vector<Bank> vecTwo;
	char ch;


	do
	{
		std::cout << "\n\t1. New Account\n";
		std::cout << "\t2. Modify Account\n";
		std::cout << "\t3. Deposit or Withdrawl\n";
		std::cout << "\t4. Display all Accounts in the Container\n";
		std::cout << "\t5. Delete Account\n";
		std::cout << "\t6. Display Account\n";
		std::cout << "\t7. Save to Text File\n";
		std::cout << "\t8. Exit Banking System\n";
		std::cout << "\tSelect your choice 1 through 7\n";
		std::cin >> ch;

		switch (ch)
		{
		case '1':
			writeAccount(vecTwo);
			break;
		case'2':
			modifyAccount(vecTwo);
			break;
		case '3':
			deposit_withdrawl(vecTwo);
			break;
		case '4':
			displayAll(vecTwo);
			break;
		case '5':
			deleteAccount(vecTwo);
			break;
		case '6':
			displayAccount(vecTwo);
			break;
		case '7':
			saveAccount(vecTwo);
			break;
		case '8':
			std::cout << "Thank you for using the banking system!" << std::endl;
			break;
		}
	} while (ch != '8');

	return 0;
}
