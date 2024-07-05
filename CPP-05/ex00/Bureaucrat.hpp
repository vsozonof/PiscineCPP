/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 07:37:37 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/05 11:40:13 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>

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
		int GradeTooLowException();
		int GradeTooHighException();
		void incrementGrade();
		void decrementGrade();
};
	
std::ostream & operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif