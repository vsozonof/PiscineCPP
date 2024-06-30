/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:49:33 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/30 15:48:57 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") {}

AMateria::AMateria(std::string const & type) : _type(type) {}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::AMateria(AMateria const & src)
{
	*this = src;
}

AMateria::~AMateria() {}

void AMateria::use(ICharacter & target)
{
	std::cout 	<< "AMateria tried to use something on " 
			  	<< target.getName() << std::endl;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}