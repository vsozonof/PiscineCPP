/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:53 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 02:08:42 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "Constructors" << std::endl;
	
	Bureaucrat b1;
	Bureaucrat b2("b2", 1);
	Bureaucrat b3("b3", 150);
	Bureaucrat b4(b2);
	Bureaucrat b5 = b3;
	
	Form f1("f1", 1, 1);
	Form f2("f2", 150, 150);
	Form f3(f1);
	Form f4 = f2;
	
	std::cout << "\nGetters" << std::endl;

	std::cout << b1 << b2 << b3 << b4 << b5;
	std::cout << f1 << f2 << f3 << f4;

	std::cout << "\nSigning forms" << std::endl;
	try
	{
		b1.signForm(f1);
		b4.signForm(f1);
		b5.signForm(f1);
		b1.signForm(f2);
		b4.signForm(f2);
		b5.signForm(f2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nGetters" << std::endl;
	std::cout << f1 << f2 << f3 << f4;


	std::cout << "\nBeSigned" << std::endl;
	f2.beSigned(b3);

	try
	{
		f4.beSigned(b4);
		f4.beSigned(b5);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "\nExecute" << std::endl;
	try
	{
		b1.executeForm(f1);
		b1.executeForm(f2);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\nDestructors" << std::endl;

	return 0;
}