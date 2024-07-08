/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:28:00 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 04:35:16 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern() {}

Intern & Intern::operator=(Intern const & rhs)
{
	if (this != &rhs)
		*this = rhs;
	return *this;
}

AForm* Intern::makePresidentialPardonForm(std::string target) 
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(std::string target) 
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeSchrubberyCreationForm(std::string target) 
{
    return new SchrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target) {
	std::string formNames[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};
	AForm* (*formCreators[3])(std::string) = {
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeSchrubberyCreationForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}

	std::cout << "Intern cannot create " << formName << std::endl;
	return NULL;
}