/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:08:34 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/30 15:40:54 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(Ice const & src) : AMateria(src)
{
	*this = src;
}

Ice & Ice::operator=(Ice const & rhs) 
{
	(void)rhs;
	return *this;
}

Ice::~Ice() {}

AMateria * Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter & target)
{
	std::cout << "Ice : shoots an ice bolt at " << target.getName() << std::endl;
}

std::string const & Ice::getType() const
{
	return _type;
}