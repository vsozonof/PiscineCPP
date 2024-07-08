/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 02:52:05 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 03:02:24 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src)
	: AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	AForm::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
	std::cout << "RobotomyRequestForm: " << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (!_signed) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _gradeToExec) {
		throw GradeTooLowException();
	}
	std::cout << "*drilling noises*" << std::endl;
	if (rand() % 2)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization of " << _target << " has failed" << std::endl;
}

