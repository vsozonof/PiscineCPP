/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:53:49 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 17:32:55 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	__type = "Dog";
}

Dog::Dog(std::string type) : Animal(type)
{
	std::cout << "Dog constructor called" << std::endl;
	__type = type;
}

Dog::Dog(Dog const & src) : Animal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog& Dog::operator=(Dog const & src)
{
	std::cout << "Dog equal operator called" << std::endl;
	if (this != &src)
		Animal::operator=(src);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}