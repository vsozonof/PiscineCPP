/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:00:54 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/10 07:52:03 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	name = "Norminet";
	HP	 = 10;
	EP	 = 10;
	AD	 = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	this->name = name;
	HP	 = 10;
	EP	 = 10;
	AD	 = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
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

void	ClapTrap::attack(const std::string& target)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << "ClapTrap: " << this->name 
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
	std::cout << "ClapTrap: " << this->name 
				<< " was attacked and lost " 
					<< amount << " hit points!" << std::endl;
	this->HP -= amount;
	if (this->HP <= 0)
		std::cout << "ClapTrap: " << this->name 
					<< " died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->EP > 0 && this->HP > 0)
	{
		std::cout << "ClapTrap: " << this->name 
						<< ", healing " << amount 
							<< " hit points!" << std::endl;
		this->EP--;
	}
	else
		std::cout << "ClapTrap: " << this->name
					<< " can't repair his self!" << std::endl;
}