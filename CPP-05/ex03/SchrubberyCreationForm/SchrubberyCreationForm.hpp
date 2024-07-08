/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SchrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 01:27:46 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 02:34:25 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCHRUUBBERYCREATIONFORM_HPP
# define SCHRUUBBERYCREATIONFORM_HPP


#include "../AForm/AForm.hpp"
#include <fstream>

class SchrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		
	public:
		SchrubberyCreationForm();
		SchrubberyCreationForm(std::string target);
		SchrubberyCreationForm(SchrubberyCreationForm const & src);
		~SchrubberyCreationForm();
		SchrubberyCreationForm & operator=(SchrubberyCreationForm const & rhs);
		void beSigned(Bureaucrat const & bureaucrat);
		void execute(Bureaucrat const & executor);

		std::runtime_error FileOpenException();
};

#endif