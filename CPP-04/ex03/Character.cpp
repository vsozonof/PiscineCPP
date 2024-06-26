/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:39:19 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 14:42:43 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	_name = "defaultName";
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(std::string const & name)
{
	std::cout << "Character constructor called" << std::endl;
	_name = name;
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(Character const & src)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = src;
}

Character & Character::operator=(Character const & rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		*_materia = *rhs._materia;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		if (_materia[i] != NULL)
			delete _materia[i];
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	int i = 0;
	while (_materia[i] != NULL)
		i++;
	if (i < 4)
	{
		_materia[i] = m;
		std::cout << "Materia equiped in slot " << i << std::endl;
	}
	else
		std::cout << "No more slots available" << std::endl;
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		_materia[idx] = NULL;
		std::cout << "Slot " << idx << " unequiped" << std::endl;
	}
	else
		std::cout << "No materia in slot " << idx << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx < 4) && _materia[idx] != NULL)
	{
		_materia[idx]->use(target);
		std::cout << "Materia used in slot " << idx << std::endl;
	}
	else
		std::cout << "No materia in slot " << idx << std::endl;
}