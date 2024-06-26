/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:49:33 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 15:13:15 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default") 
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "AMateria constructor called" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
	std::cout << "AMateria assignation operator called" << std::endl;
	if (this != &rhs)
		_type = rhs._type;
	return *this;
}

AMateria::AMateria(AMateria const & src)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = src;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

void AMateria::use(ICharacter & target)
{
	std::cout 	<< "AMateria tried to use something on " 
			  	<< target.getName() << std::endl;
}

std::string const & AMateria::getType() const
{
	return _type;
}