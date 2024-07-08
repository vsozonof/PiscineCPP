/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:10:45 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 03:15:01 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src)
	: AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	AForm::operator=(rhs);
	return *this;
}

void PresidentialPardonForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
	std::cout << "PresidentialPardonForm: " << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (!_signed) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _gradeToExec) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}