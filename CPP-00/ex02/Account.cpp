/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:52:40 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/29 11:26:01 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit):
	_amount(initial_deposit),
	_nbDeposits(0),
	_nbWithdrawals(0)
	{
		_accountIndex = _nbAccounts++;
		_totalAmount += initial_deposit;
		_totalNbDeposits++;
		_displayTimestamp();	
		std::cout << "index:" << _accountIndex 
					<< ";amount:" << _amount 
						<< ";created" << std::endl;
	}

Account::~Account()
{
	_displayTimestamp();	
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount 
					<< ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);
	std::cout << std::put_time(std::localtime(&in_time_t), "[%Y%m%d_%H%M%S] ");
}

void 	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
				<< ";total:" << getTotalAmount() 
					<< ";deposits:" << getNbDeposits()
						<< ";withdrawals:" << getNbWithdrawals()
							<< std::endl;
}

int		Account::getNbAccounts()
{
	return _nbAccounts;
}

int 	Account::getTotalAmount()
{
	return _totalAmount;
}

int 	Account::getNbDeposits()
{
	return _totalNbDeposits;
}

int 	Account::getNbWithdrawals()
{
	return _totalNbWithdrawals;
}


void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount
					<< ";deposit:" << deposit
						<< ";amount:" << _amount + deposit
							<< ";nb_deposits:" << _nbDeposits + 1
								<< std::endl;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits += 1;
	_totalNbDeposits += 1;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
					<< ";deposits:" << _nbDeposits
						<< ";withdrawals:" << _nbWithdrawals
							<< std::endl;
}

int main ()
{
	Account account(500);
	account.displayStatus();
	account.makeDeposit(100);
	account.displayStatus();
	
}