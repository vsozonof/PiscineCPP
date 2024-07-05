/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:12:16 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/05 10:02:24 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(std::string const name, int const gradeToSign, int const gradeToExec) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(Form const & src) :
	_name(src._name), _gradeToSign(src._gradeToSign),
	_gradeToExec(src._gradeToExec), _signed(src._signed)
{
}

Form::~Form()
{
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

std::string const & Form::getName() const
{
	return _name;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

bool Form::getSigned() const
{
	return _signed;
}

void Form::beSigned(const Bureaucrat & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign) 
		throw Form::GradeTooLowException();
	else if (_signed)
		std::cout << bureaucrat.getName() << " cannot sign " << _name << " because form is already signed" << std::endl;
	else
	{
		_signed = true;
		std::cout << bureaucrat.getName() << " signs " << _name << std::endl;
	}
}

std::ostream & operator<<(std::ostream & o, Form const & form)
{
	o << "Form " << form.getName() << " is ";
	if (form.getSigned())
		o << "signed" << std::endl;
	else 
	{
		o << "not signed";
		o << " and requires grade " << form.getGradeToSign() 
		  << " to sign and grade " << form.getGradeToExec() << " to execute" << std::endl;
	}
	return o;
}

int Form::GradeTooHighException()
{
	std::cout << "Grade is too high" << std::endl;
	return 0;
}

int Form::GradeTooLowException()
{
	std::cout << "Grade is too low" << std::endl;
	return 0;
}

