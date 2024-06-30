/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:20:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/30 15:32:08 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(Cure const & src) : AMateria(src)
{
	*this = src;
}

Cure & Cure::operator=(Cure const & rhs)
{
	(void)rhs;
	return *this;
}

Cure::~Cure() {}

AMateria * Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter & target)
{
	std::cout << "Cure : heals " << target.getName() << "'s wounds" << std::endl;
}