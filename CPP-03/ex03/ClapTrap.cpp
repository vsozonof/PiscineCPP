/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:00:54 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 10:49:08 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap constructor called" << std::endl;
	name = "Norminet";
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap Name constructor called" << std::endl;
	this->name = name;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &f)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = f.name;
	this->HP = f.HP;
	this->EP = f.EP;
	this->AD = f.AD;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f)
{
	std::cout << "Equal operator overload called" << std::endl;
	if (this != &f)
	{
		this->name = f.name;
		this->HP = f.HP;
		this->EP = f.EP;
		this->AD = f.AD;
	}
	return *this;
}

void	ClapTrap::announce(void)
{
	std::cout << "ClapTrap: ";
}


void	ClapTrap::attack(const std::string& target)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << this->name 
					<< " attacks " << target 
						<< ", causing " << this->AD 
							<< " points of damage!" << std::endl;
		this->EP--;
	}
	else
		std::cout << "ClapTrap: " << this->name
					<< " can't attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->name << " was attacked and lost " 
					<< amount << " hit points!" << std::endl;
	this->HP -= amount;
	if (this->HP <= 0)
		std::cout << this->name << " died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << this->name  << ", healing " << amount 
					<< " hit points!" << std::endl;
		this->EP--;
	}
	else
		std::cout << this->name << " can't repair his self!" << std::endl;
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

std::string ClapTrap::getName(void)
{
	return this->name;
}

void	ClapTrap::setHp(unsigned int amount)
{
	this->HP = amount;
}

void	ClapTrap::setEp(unsigned int amount)
{
	this->EP = amount;
}

void	ClapTrap::setAd(unsigned int amount)
{
	this->AD = amount;
}

int		ClapTrap::getHp(void)
{
	return this->HP;
}
int		ClapTrap::getEp(void)
{
	return this->EP;
}

int		ClapTrap::getAd(void)
{
	return this->AD;
}
