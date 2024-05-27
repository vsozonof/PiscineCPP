/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 07:17:00 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/27 10:15:20 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug();
		void warning();
		void info();
		void error();

	public:
		Harl();
		~Harl();
		void complain(std::string level);
		typedef void (Harl::*HarlMemberFct)();
};

#endif