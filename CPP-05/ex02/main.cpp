/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:53 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 03:17:17 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SchrubberyCreationForm/SchrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"


int main()
{
	std::cout << "Constructors" << std::endl;
	SchrubberyCreationForm form("home");
	RobotomyRequestForm form2("Vlad");
	PresidentialPardonForm form3("Vlad");
	Bureaucrat bureaucrat("Vlad", 137);
	Bureaucrat bureaucrat2("Vlad2", 1);

	std::cout << "\nSign form" << std::endl;
	bureaucrat.executeForm(form);
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);

	std::cout << "\nSign form2" << std::endl;
	bureaucrat2.executeForm(form2);
	bureaucrat2.signForm(form2);
	bureaucrat2.executeForm(form2);

	std::cout << "\nSign form3" << std::endl;
	bureaucrat.executeForm(form3);
	bureaucrat.signForm(form3);
	bureaucrat2.signForm(form3);
	bureaucrat.executeForm(form3);
	bureaucrat2.executeForm(form3);
	

	std::cout << "\nDestructors" << std::endl;

	return 0;
}