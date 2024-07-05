/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:37:37 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/05 09:40:15 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat(std::string const name, int grade);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & rhs);
		std::string const & getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		int GradeTooLowException();
		int GradeTooHighException();
		void signForm(Form &form);
};
	
std::ostream & operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif