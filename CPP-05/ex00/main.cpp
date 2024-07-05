/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:53 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/05 09:04:55 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Bureaucrat tests" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Creating bureaucrats with valid grade" << std::endl;
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	Bureaucrat b3(b1);
	Bureaucrat b4 = b2;

	b3 = b4;

	std::cout << b1 << b2 << b3 << b4;

	std::cout << "\nTrying to increment / decrement" << std::endl;
	try
	{
		b1.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		b2.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl; 
	}
	std::cout << "\nCreating bureaucrats with invalid grade" << std::endl;
	try
	{
		Bureaucrat b5("b5", 0);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b6("b6", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nDestructors" << std::endl;

	return 0;
}