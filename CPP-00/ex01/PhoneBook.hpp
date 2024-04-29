/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:05:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/29 07:28:04 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>


class PhoneBook {
	
	private:
		Contact 	contacts[8];
		int			count;

	public:
		PhoneBook() : count(0) {
		}
		void		addContact();
		void		printContact();
		void		searchContact();
		std::string	getContactInfos();

};

#endif