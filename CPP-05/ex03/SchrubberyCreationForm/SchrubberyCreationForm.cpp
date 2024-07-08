/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:30:01 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 02:56:55 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SchrubberyCreationForm.hpp"

// ! ***************************************************************************
// ? **************************** CONSTRUCTORS *********************************
// ? ***** COPY CONSTRUCTOR, ASSIGNATION OPERATOR AND DESTRUCTOR ARE DEFAULT ***
// ! ***************************************************************************

SchrubberyCreationForm::SchrubberyCreationForm()
	: AForm("Schrubbery Form", 145, 137), _target("default") {}

SchrubberyCreationForm::SchrubberyCreationForm(std::string target)
	: AForm("Schrubbery Form", 145, 137), _target(target) {}
	
SchrubberyCreationForm::SchrubberyCreationForm(SchrubberyCreationForm const & src)
	: AForm(src), _target(src._target) {}
	
SchrubberyCreationForm::~SchrubberyCreationForm() {}

SchrubberyCreationForm & SchrubberyCreationForm::operator=(SchrubberyCreationForm const & rhs)
{
	AForm::operator=(rhs);
	return *this;
}

// ! ***************************************************************************
// ? ****************************** FORM FUNCTIONS *****************************
// ! ***************************************************************************

void SchrubberyCreationForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_signed = true;
	std::cout << "SchrubberyCreationForm: " << _name << " has been signed by " << bureaucrat.getName() << std::endl;
}

void SchrubberyCreationForm::execute(Bureaucrat const & executor) 
{
	if (!_signed) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > _gradeToExec) {
		throw GradeTooLowException();
	}

	std::ofstream file((_target + "_shrubbery").c_str());
	std::ifstream tree("utils/AsciiTree.txt");

	

	if (!tree.is_open() || !file.is_open()) {
		throw FileOpenException();
	}

	std::string line;
	while (std::getline(tree, line)) {
		file << line << std::endl;
	}
	tree.close();
	file.close();
	std::cout << "SchrubberyCreationForm: " << _name << " has been executed by " << executor.getName() << std::endl;
}


// ! ***************************************************************************
// ? ****************************** EXCEPTIONS ********************************
// ! ***************************************************************************

std::runtime_error SchrubberyCreationForm::FileOpenException() 
{
	return std::runtime_error("File open error");
}


	