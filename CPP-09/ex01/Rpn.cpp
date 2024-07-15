/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 06:53:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/15 08:00:53 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

Rpn::Rpn() {}

Rpn::~Rpn() {}

Rpn::Rpn(const Rpn &src)
{
	*this = src;
}

Rpn &Rpn::operator=(const Rpn &rhs)
{
	if (this == &rhs)
		return (*this);
	return (*this);
}

void Rpn::parseArgs(std::string &str)
{
	std::stack<int> stack;
	std::string out;

	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
			continue;
		else if (str[i] >= '0' && str[i] <= '9')
			stack.push(str[i] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (stack.size() < 2)
				throw std::invalid_argument(BOLD_RED "Error: Invalid expression" def);
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (str[i] == '+')
				stack.push(b + a);
			if (str[i] == '-')
				stack.push(b - a);
			if (str[i] == '*')
				stack.push(b * a);
			if (str[i] == '/')
			{
				if (a == 0)
					throw std::invalid_argument(BOLD_RED "Error: Division by zero" def);
				stack.push(b / a);
			}
		}
		else
			throw std::invalid_argument(BOLD_RED "Error: Invalid character in expression" def);
	}
	if (stack.size() != 1)
		throw std::invalid_argument(BOLD_RED "Error: Invalid expression" def);
	std::cout << BOLD_GREEN "Success: " def << "result = " << stack.top() << std::endl;
}