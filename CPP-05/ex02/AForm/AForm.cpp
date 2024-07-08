/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:12:16 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 02:46:21 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "../Bureaucrat/Bureaucrat.hpp"


// ! **************************************************************************
// ? ******* Constructors, Destructor and operator overload    ****************
// ! **************************************************************************

AForm::AForm() : _name("default"), _gradeToSign(150), _gradeToExec(150), _signed(false) 
{}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExec) :
	_name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false)
{
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw GradeTooHighException();
	}
	if (gradeToSign > 150 || gradeToExec > 150) {
		throw GradeTooLowException();
	}
}

AForm::AForm(AForm const & src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec), _signed(src._signed) {}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & rhs)
{
	if (this != &rhs) {
		_signed = rhs._signed;
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, AForm const & form)
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

// ! **************************************************************************
// ? *************************** Getters and setters **************************
// ! **************************************************************************

std::string const & AForm::getName() const
{
	return _name;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

bool AForm::getSigned() const
{
	return _signed;
}

// ! **************************************************************************
// ? *************************** Exception  ***********************************
// ! **************************************************************************

std::out_of_range AForm::GradeTooHighException()
{
	throw std::out_of_range("Grade is too high");
}

std::out_of_range AForm::GradeTooLowException()
{
	throw std::out_of_range("Grade is too low");
}

std::out_of_range AForm::FormNotSignedException()
{
	throw std::out_of_range("Form is not signed");
}

