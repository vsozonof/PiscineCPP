/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:09:16 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 03:11:41 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "../AForm/AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string const _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
		virtual ~PresidentialPardonForm();

		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const & executor);
};

#endif