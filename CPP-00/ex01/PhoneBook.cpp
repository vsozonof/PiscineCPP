/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:04:47 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/14 18:03:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::addContact()
{
	static int		index;

	if (index == 7)
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
	if (count < 7)
		count++;
}

std::string	PhoneBook::getContactInfos() {
	std::string		input;
	
	while (42) {
		std::getline(std::cin, input);
		if (!input.empty())
			break ;
		else
			std::cout << "\e[1;31m" << "Error: Invalid input\e[0m \e[1;32m\nTry again :\t" << "\e[0m";
	}
	return (input);
}

void	PhoneBook::searchContact(int index)
{

	printf("SearchContact called %i", index);
}


void	PhoneBook::printContact()
{
	int	index = 0;
	
	printf("Printing Contacts\n");
	while (index < count)
	{
		std::cout << contacts[index].getFirstName() << std::endl;
		std::cout << contacts[index].getLastName() << std::endl;
		std::cout << contacts[index].getNickName() << std::endl;
		std::cout << contacts[index].getPhone() << std::endl;
		std::cout << contacts[index].getSecret() << std::endl;
		index++;
	}
}