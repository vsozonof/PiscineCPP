/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:56:53 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 06:48:58 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SchrubberyCreationForm/SchrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "Bureaucrat/Bureaucrat.hpp"
#include "AForm/AForm.hpp"
#include "Intern/Intern.hpp"


int main()
{
	std::cout << "Constructors" << std::endl;
	Intern intern;
	Bureaucrat bureaucrat("Bureaucrat", 1);

	std::cout << "\nIntern makeForm" << std::endl;
	AForm *form1 = intern.makeForm("shrubbery creation", "target1");
	AForm *form2 = intern.makeForm("robotomy request", "target2");
	AForm *form3 = intern.makeForm("presidential pardon", "target3");
	
	
	std::cout << "\nBureaucrat signForm" << std::endl;
	bureaucrat.signForm(*form1);
	std::cout << "\n";
	bureaucrat.signForm(*form2);
	std::cout << "\n";
	bureaucrat.signForm(*form3);

	std::cout << "\nBureaucrat executeForm" << std::endl;
	bureaucrat.executeForm(*form1);
	std::cout << "\n";
	bureaucrat.executeForm(*form2);
	std::cout << "\n";
	bureaucrat.executeForm(*form3);

	delete form1;
	delete form2;
	delete form3;
	

	std::cout << "\nDestructors" << std::endl;

	return 0;
}