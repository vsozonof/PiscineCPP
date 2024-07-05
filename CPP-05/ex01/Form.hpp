/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:07:31 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/05 10:10:42 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		int const _gradeToSign;
		int const _gradeToExec;
		bool _signed;

	public:
		Form(std::string const name, int gradeToSign, int gradeToExec);
		Form(Form const &src);
		Form & operator=(Form const & rhs);
		~Form();

		std::string const & getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		void beSigned(Bureaucrat const &bureaucrat);
		int GradeTooLowException();
		int GradeTooHighException();	
};

std::ostream & operator<<(std::ostream& os, const Form& rhs);

#endif