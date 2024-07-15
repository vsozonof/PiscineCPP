/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:38:22 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/14 18:12:22 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange()
{
	std::ifstream file("data.csv");

	if (!file.is_open())
		throw std::runtime_error("Could not open file");

	std::string line;
	for (int i = 0; std::getline(file, line); i++)
	{
		if (i == 0)
			continue;
		std::string date = line.substr(0, line.find(','));
		std::string price = line.substr(line.find(',') + 1);
		_exchange[date] = atof(price.c_str());
	}

	if (_exchange.empty())
		throw std::runtime_error("Server Database is empty");
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
		this->_exchange = rhs._exchange;
	return (*this);
}

void BitcoinExchange::printExchange()
{
	if (_exchange.empty())
		throw std::runtime_error("Server Database is empty");
	for (std::map<std::string, double>::iterator it = _exchange.begin(); it != _exchange.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}

double BitcoinExchange::getRate(std::string date)
{
	if (_exchange.empty())
		throw std::runtime_error("Server Database is empty");

	std::map<std::string, double>::iterator it = _exchange.find(date);
	if (it != _exchange.end())
		return it->second;
	else
	{
		std::map<std::string, double>::iterator closest = _exchange.end();
		for (it = _exchange.begin(); it != _exchange.end(); ++it)
		{
			if (it->first <= date && (closest == _exchange.end() || closest->first < it->first))
				closest = it;
		}
		if (closest == _exchange.end())
			throw std::runtime_error("No data available for this date");
		return closest->second;
	}
}