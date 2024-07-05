/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:42:00 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/05 08:10:28by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	const_cast<std::string&>(this->_name) = "default";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string const name, int grade)
{
	std::cout << "Bureaucrat name constructor called" << std::endl;
	const_cast<std::string&>(this->_name) = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	std::cout << "Bureaucrat assignation operator called" << std::endl;
	if (this != &rhs)
	{
		const_cast<std::string&>(this->_name) = rhs._name;	
		this->_grade = rhs._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string const & Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}	

int Bureaucrat::GradeTooLowException()
{
	throw std::runtime_error("Grade too low");
}	

int Bureaucrat::GradeTooHighException()
{
	throw std::runtime_error("Grade too high");
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

std::ostream & operator<<(std::ostream& os, Bureaucrat const & rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return os;
}

