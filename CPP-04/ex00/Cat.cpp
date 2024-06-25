/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:45:54 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 17:33:05 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	__type = "Cat";
}

Cat::Cat(std::string type) : Animal(type)
{
	std::cout << "Cat constructor called" << std::endl;
	__type = type;
}

Cat::Cat(Cat const & src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat& Cat::operator=(Cat const & src)
{
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
		__type = src.getType();
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}