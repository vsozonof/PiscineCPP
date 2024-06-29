/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:53:49 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/29 21:02:13 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal()
{
	std::cout << "Dog constructor called" << std::endl;
	__type = "Dog";
	_brain = new Brain();
}

Dog::Dog(std::string type) : AAnimal(type)
{
	std::cout << "Dog constructor called" << std::endl;
	__type = type;
	_brain = new Brain();
}

Dog::Dog(Dog const & src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=(Dog const & src)
{
	std::cout << "Dog equal operator called" << std::endl;
	if (this != &src)
	{
		__type = src.getType();
		_brain = new Brain(*src._brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}