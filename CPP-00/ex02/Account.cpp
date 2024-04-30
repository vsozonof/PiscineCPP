/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 07:52:40 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/30 15:00:09 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
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
	time_t now = time(NULL);
	struct tm *timeinfo = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);

    std::cout << buffer;
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

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			<< ";p_amount:" << _amount;
	if (withdrawal <= _amount)
	{
		std::cout << ";withdrawal:" << withdrawal
					<< ";amount:" << _amount - withdrawal
						<< ";nb_withdrawals:" << _nbWithdrawals + 1
							<< std::endl;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals += 1;
		_totalNbWithdrawals += 1;
	}
	else
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (1);
	}
	return (0);
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
