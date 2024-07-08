/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:23:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 04:15:17 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
# include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
# include "../SchrubberyCreationForm/SchrubberyCreationForm.hpp"

class Bureaucrat;
class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern
{
	private:
		static AForm* makePresidentialPardonForm(std::string target);
		static AForm* makeRobotomyRequestForm(std::string target);
		static AForm* makeSchrubberyCreationForm(std::string target);
	
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();
		Intern & operator=(Intern const & rhs);
		AForm* makeForm(std::string formName, std::string target);
};

#endif