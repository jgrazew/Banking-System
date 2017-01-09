//Header

#ifndef BANKSYSTEM2_H
#define BANKSYSTEM2_H

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Bank
{
private:
	std::string m_name;
	int m_deposit;
	int m_accountNum;
	std::string m_accountType;

public:

	
	//friend functions
	friend void deleteAccount(std::vector<Bank>&); 
	friend void saveAccount(std::vector<Bank>&);		  

	//constructors
	Bank() : m_name(" "), m_deposit(0), m_accountNum(0), m_accountType(" ") { };
	Bank(std::string name, int deposit, int accountNum, std::string accountType) :
		m_name(name), m_deposit(deposit), m_accountNum(accountNum), m_accountType(accountType) { };
	

	//member functions that are implicitly inline below
	std::string accountHolder() const { return m_name; } 
	int accountNumber() const { return m_accountNum; }
	//member function declarations below
	void deposit(int);
	void withdrawl(int);
	int returnBalance() const;
	void showAccount() const;
	void modify();
	void createAccount();
};

//Non member interface functions
//std::ostream &print(std::ostream&, Bank&);

void writeAccount(std::vector<Bank>&); 
void modifyAccount(std::vector<Bank>&);
void deposit_withdrawl(std::vector<Bank>&);
void displayAll(const std::vector<Bank>&);
void deleteAccount(std::vector<Bank>&);
void displayAccount(const std::vector<Bank>&);
void saveAccount(std::vector<Bank>&); 




#endif // !BANKSYSTEM_H
