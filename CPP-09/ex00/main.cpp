/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 07:41:41 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/15 06:44:49 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cstdlib>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define DEFAULT "\033[0m"

void checkValidity(const std::string &date, double amount, BitcoinExchange& rate)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-' || date.empty())
		throw std::runtime_error(RED "Invalid date format" DEFAULT);

	else if (date.substr(4, 1) != "-" || date.substr(7, 1) != "-" || date.size() != 10)
        std::cout << RED "Error: " DEFAULT << date << "-" << amount << "\n🠮 Date format is incorrect" DEFAULT << std::endl;
    else if (date.substr(0, 4) < "2000" || date.substr(0, 4) > "2024")
        std::cout << RED "Error: " DEFAULT << date << "-" << amount << "\n🠮 Year out of range" DEFAULT << std::endl;
    else if (date.substr(5, 2) < "01" || date.substr(5, 2) > "12")
        std::cout << RED "Error: " DEFAULT << date << "-" << amount << "\n🠮 Month out of range" DEFAULT << std::endl;
    else if (date.substr(8, 2) < "01" || date.substr(8, 2) > "31")
        std::cout << RED "Error: " DEFAULT << date << "-" << amount << "\n🠮 Day out of range" DEFAULT << std::endl;
    else if (amount <= 0 || amount > 1000)
        std::cout << RED "Error: " DEFAULT << date << " - " << amount << "\n🠮 Value out of range" DEFAULT << std::endl;
    else
        std::cout << GREEN "Success: " DEFAULT << date << " " << amount
				  << "\n🠮 " << amount << " Bitcoint value equals : " << (rate.getRate(date) * amount) << std::endl;
}

void readAccounts(char *str, BitcoinExchange& rate)
{
	std::ifstream file(str);

	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	
	std::string line;
	while (std::getline(file, line))
	{
		std::string date = line.substr(0, line.find('|'));
		std::string price = line.substr(line.find('|', date.size()) + 1);

		if (date[date.size() - 1] == ' ')
			date = date.substr(0, date.size() - 1);
		if (price[0] == ' ')
			price = price.substr(1, price.size());
		
		double amount = atof(price.c_str());
		checkValidity(date, amount, rate);
	}

}


int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./ex00 [filename]" << std::endl;
		return (1);
	}
	
	try
	{
		BitcoinExchange exchange;
		readAccounts(argv[1], exchange);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}

	return (0);
}