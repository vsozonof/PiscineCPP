/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:04:47 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/29 07:44:45 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact()
{
	static int		index;

	if (index == 8)
		index = 0;
	std::cout << "\e[1;32m" << "Enter the contact's first name :\t" << "\e[0m";
	contacts[index].setFirstName(getContactInfos());
	std::cout << "\e[1;32m" << "Enter the contact's last name :\t" << "\e[0m";
	contacts[index].setLastName(getContactInfos());
	std::cout << "\e[1;32m" << "Enter the contact's nickname :\t" << "\e[0m";
	contacts[index].setNickName(getContactInfos());
	std::cout << "\e[1;32m" << "Enter the contact's phone number :\t" << "\e[0m";
	contacts[index].setPhone(getContactInfos());
	std::cout << "\e[1;32m" << "Enter the contact's darkest secret :\t" << "\e[0m";
	contacts[index].setSecret(getContactInfos());
	index++;
	if (count <= 7)
		count++;
}

std::string	PhoneBook::getContactInfos() 
{
	std::string		input;
	
	while (std::getline(std::cin, input))
	{
		if (!input.empty())
			break ;
		else
			std::cout << "\e[1;31m" << "Error: Invalid input\e[0m \e[1;32m\nTry again :\t" << "\e[0m";
	}
	return (input);
}

void	PhoneBook::searchContact()
{
	std::string	index;
	
	std::cout << "\e[1;32m" << "\nEnter the index of the contact you want to see :\t" << "\e[0m";
	while (std::getline(std::cin, index))
	{
		if (!index.empty() && (atoi(index.data()) >= 1 && atoi(index.data()) <= 8))
			break ;
		else
			std::cout << "\e[1;31m" << "Error: Invalid input\e[0m \e[1;32m\nTry again :\t" << "\e[0m";
	}

	std::cout << "Here are the informations for the contact number " << atoi(index.data()) << std::endl;
	std::cout << "First Name :" << contacts[atoi(index.data()) - 1].getFirstName() << std::endl;
	std::cout <<	"Last Name :" << contacts[atoi(index.data()) - 1].getLastName() << std::endl;
	std::cout << "Nickname :" << contacts[atoi(index.data()) - 1].getNickName() << std::endl;
	std::cout << "Phone Number :" << contacts[atoi(index.data()) - 1].getPhone() << std::endl;
	std::cout << "Darkest Secret :" << contacts[atoi(index.data()) - 1].getSecret() << std::endl;
}


void	PhoneBook::printContact()
{
	std::cout << "\n|-------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(28) << "CONTACT LIST" << std::setw(16) << "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "F. Name";
	std::cout << "|" << std::setw(10) << "L. Name";
	std::cout << "|" << std::setw(10) << "N. Name"	<< "|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	
	for (int index = 0; index <= 7; index++)
	{
		std::cout << "|" << std::setw(10) << (index + 1);
		if (contacts[index].getFirstName().length() > 10)
			std::cout << "|" << std::setw(9) << contacts[index].getFirstName().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << contacts[index].getFirstName();
		if (contacts[index].getLastName().length() > 10)
			std::cout << "|" << std::setw(9) << contacts[index].getLastName().substr(0, 9) << ".";
		else
			std::cout << "|" << std::setw(10) << contacts[index].getLastName();
		if (contacts[index].getNickName().length() > 10)
			std::cout << "|" << std::setw(9) << contacts[index].getNickName().substr(0, 9) << "." << "|" << std::endl;
		else
			std::cout << "|" << std::setw(10) << contacts[index].getNickName() << "|" << std::endl;
		std::cout << "|-------------------------------------------|" << std::endl;
	}
	searchContact();
}