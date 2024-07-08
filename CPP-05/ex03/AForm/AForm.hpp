/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:07:31 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 02:35:07 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "../Bureaucrat/Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string const _name;
		int const _gradeToSign;
		int const _gradeToExec;
		bool _signed;

	public:
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExec);
		AForm(AForm const &src);
		AForm & operator=(AForm const & rhs);
		virtual ~AForm();

		std::string const & getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;
		virtual void beSigned(Bureaucrat const &bureaucrat) = 0;
		virtual void execute(Bureaucrat const & executor) = 0;
		std::out_of_range GradeTooLowException();
		std::out_of_range GradeTooHighException();
		std::out_of_range FormNotSignedException();
};

std::ostream & operator<<(std::ostream& os, const AForm& rhs);

#endif