/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:36:12 by vsozonof          #+#    #+#             */
/*   Updated: 2024/04/14 17:19:55 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <cstdio>


class Contact {
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact(std::string first = "", std::string last = "", std::string nick = "", 
				std::string phone = "", std::string secret = "");
		void			setFirstName(std::string first);
		void			setLastName(std::string last);
		void			setNickName(std::string nick);
		void			setPhone(std::string phone);
		void			setSecret(std::string secret);
		std::string		getFirstName();
		std::string		getLastName();
		std::string		getNickName();
		std::string		getPhone();
		std::string		getSecret();
};

#endif