/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:14:27 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 09:45:18 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	__type = "Animal";
}

Animal::Animal(std::string type)
{
	std::cout << "Animal constructor called" << std::endl;
	__type = type;
}

Animal::Animal(Animal const & src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal& Animal::operator=(Animal const & src)
{
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &src)
		__type = src.getType();
	return *this;
}


std::string Animal::getType() const
{
	return __type;
}

void Animal::makeSound() const
{
	std::cout << "Weird and unknown sound" << std::endl;
}