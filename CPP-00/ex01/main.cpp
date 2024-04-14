/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:56:11 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/14 17:37:51 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook		phonebook;
	std::string		input;

	std::cout << "\e[4;33m" << "\t\t ☎️  Welcome to the PhoneBook ☎️  \n" << "\e[0m" << std::endl;
	std::cout << "\e[1;33m" << "Available commands :" << std::endl;
	std::cout << "• ADD		: Adds a contact to the PhoneBook" << std::endl;
	std::cout << "• SEARCH	: Searches for a contact in the PhoneBook" << std::endl;
	std::cout << "• EXIT		: Exits the PhoneBook\n\n" << "\e[0m" << std::endl;

	while (42) {
		std::cout << "\e[1;32m" << "Enter a command :\t" << "\e[0m";
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.printContact();
		else
			std::cout << "\e[1;31m" << "Invalid input !" << "\e[0m" << std::endl;
	}
	return (0);
}