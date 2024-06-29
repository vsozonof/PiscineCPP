/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:58:32 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/29 22:51:46 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (src.materia[i])
			materia[i] = src.materia[i]->clone();
		else
			materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &rhs)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (materia[i])
				delete materia[i];
			if (rhs.materia[i])
				materia[i] = rhs.materia[i]->clone();
			else
				materia[i] = NULL;
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;
	while (i < 4 && materia[i] != NULL)
		i++;
	if (i < 4)
	{
		materia[i] = m;
		std::cout << "Materia learnt in slot " << i << std::endl;
	}
	else
	{
		delete m;
		std::cout << "MateriaSource is full, the materia is lost" << std::endl;
	}
}

AMateria * MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4 && materia[i] != NULL)
		i++;
	if (i == 4)
		return NULL;
	if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	return NULL;
}