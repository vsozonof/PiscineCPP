/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:53:07 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/15 08:00:44 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>

#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define def "\033[0m"

class Rpn
{
	public:
		Rpn();
		Rpn(const Rpn &src);
		~Rpn();

		Rpn &operator=(const Rpn &rhs);

		void parseArgs(std::string &str);
};

#endif
