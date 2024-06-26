/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:20:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 14:42:02 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(Cure const & src)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = src;
}

Cure & Cure::operator=(Cure const & rhs)
{
	std::cout << "Cure assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria * Cure::clone() const
{
	std::cout << "Cure clone called" << std::endl;
	return new Cure(*this);
}

void Cure::use(ICharacter & target)
{
	std::cout << "Cure : heals " << target.getName() << "'s wounds" << std::endl;
}