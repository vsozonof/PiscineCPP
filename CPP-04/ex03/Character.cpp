/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:39:19 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/30 15:34:18 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	_name = "defaultName";
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
		_dropped[i] = NULL;
	}
}

Character::Character(std::string const & name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
	{
		_materia[i] = NULL;
		_dropped[i] = NULL;
	}
}

Character::Character(Character const & src)
{
	*this = src;
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		_name = rhs._name;
		for (int i = 0; i < 4; i++)
		{
			_materia[i] = rhs._materia[i];
			_dropped[i] = rhs._dropped[i];
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_materia[i] != NULL)
			delete _materia[i];
	for (int i = 0; i < 4; i++)
		if (_dropped[i] != NULL)
			delete _dropped[i];
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cout << "Trying to equip a NULL materia" << std::endl;
		return;
	}
	
	int i = 0;
	while (i < 4 && _materia[i] != NULL)
		i++;
	if (i < 4)
	{
		_materia[i] = m;
		std::cout << "Materia equiped in slot " << i << std::endl;
	}
	else
	{
		i = 0;
		while (i < 4 && _dropped[i] != NULL)
			i++;
		if (i < 4)
		{
			_dropped[i] = m;
			std::cout << "No more slots available in the inventory, the materia is dropped on the floor." << std::endl;
		}
		else
		{
			delete m;
			std::cout << "No more slots available in the inventory and on the floor, the materia is lost." << std::endl;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
	{
		int i = 0;
		while (_dropped[i] != NULL)
			i++;
		if (i < 4)
		{
			_dropped[i] = _materia[idx];
			_materia[idx] = NULL;
			std::cout << "Slot " << idx << " unequiped, and was dropped on the floor" << std::endl;
		}
		else
		{
			delete _dropped[0];
			_dropped[0] = _materia[idx];
			_materia[idx] = NULL;
			std::cout << "Slot " << idx << " unequiped, and was dropped on the floor, the materia fell on another materia and destroyed it..." << std::endl;
		}
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