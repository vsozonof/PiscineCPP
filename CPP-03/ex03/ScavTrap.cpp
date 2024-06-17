/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:16:59 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 09:52:12 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	std::cout << "ScavTrap constructor called"
				<< std::endl;
	setEp(50);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called"
				<< std::endl;
	setEp(50);
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called"
			<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap &f)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	this->setName(f.getName());
	this->setHp(f.getHp());
	this->setEp(f.getEp());
	this->setAd(f.getAd());
}

ScavTrap &ScavTrap::operator=(ScavTrap &f)
{
	std::cout << "ScavTrap equal operator overload called" << std::endl;
	if (this != &f)
	{
		this->setName(f.getName());
		this->setHp(f.getHp());
		this->setEp(f.getEp());
		this->setAd(f.getAd());
	}
	return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << getName() << " now in guard mode" << std::endl;
}

void ScavTrap::announce(void)
{
	std::cout << "ScavTrap : ";
}

void ScavTrap::attack(const std::string& target)
{
	ScavTrap::announce();
	ClapTrap::attack(target);
}

void ScavTrap::takeDamage(unsigned int amount)
{
	ScavTrap::announce();
	ClapTrap::takeDamage(amount);
}

void ScavTrap::beRepaired(unsigned int amount)
{
	ScavTrap::announce();
	ClapTrap::beRepaired(amount);
}