/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:58:32 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/30 15:47:59 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (materia[i])
			delete materia[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
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
	while (i < 4 && materia[i] != NULL && materia[i]->getType() != type)
		i++;
	if (i < 4 && materia[i] != NULL)
	{
		std::cout << "Materia found" << std::endl;
		return materia[i]->clone();
	}
	std::cout << "Materia not found" << std::endl;
	return 0;
}