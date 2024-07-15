/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 07:09:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/15 08:00:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Rpn.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
		return (1);
	}
	try
	{
		Rpn rpn;
		std::string str(av[1]);
		rpn.parseArgs(str);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}