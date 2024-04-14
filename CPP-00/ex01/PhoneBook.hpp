/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:05:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/14 17:52:43 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdio>
#include <string>
#include <iostream>
#include <iomanip>


class PhoneBook {
	
	private:
		Contact 	contacts[8];
		int			count;

	public:
		PhoneBook() : count(0) {
		}
		void		addContact();
		void		printContact();
		void		searchContact(int index);
		std::string	getContactInfos();

};

#endif