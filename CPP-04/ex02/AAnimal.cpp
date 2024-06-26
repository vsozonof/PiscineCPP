/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:27 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 10:09:55 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "AAnimal constructor called" << std::endl;
	__type = "AAnimal";
}

AAnimal::AAnimal(std::string type)
{
	std::cout << "AAnimal constructor called" << std::endl;
	__type = type;
}

AAnimal::AAnimal(AAnimal const & src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const & src)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &src)
		__type = src.getType();
	return *this;
}


std::string AAnimal::getType() const
{
	return __type;
}