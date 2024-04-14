/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:36:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/14 17:24:15 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(std::string first, std::string last, std::string nick, 
				std::string phone, std::string secret)
		: firstName(first), lastName(last), nickName(nick), phoneNumber(phone),
		darkestSecret(secret) {
		}

void	Contact::setFirstName(std::string first) {
	firstName = first;
}

std::string		Contact::getFirstName() {
	return (firstName);
}

void	Contact::setLastName(std::string last) {
	lastName = last;
}

std::string		Contact::getLastName() {
	return (lastName);
}

void	Contact::setNickName(std::string nick) {
	nickName = nick;
}

std::string		Contact::getNickName() {
	return (nickName);
}

void	Contact::setPhone(std::string phone) {
	phoneNumber = phone;
}

std::string		Contact::getPhone() {
	return (phoneNumber);
}

void	Contact::setSecret(std::string secret) {
	darkestSecret = secret;
}

std::string		Contact::getSecret() {
	return (darkestSecret);
}