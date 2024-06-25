/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:16:59 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 01:33:43 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	std::cout << "ScavTrap constructor called"
				<< std::endl;
	__HitPoints = 100;
	__AttackDamage = 20;
	__EnergyPoints = 50;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called"
				<< std::endl;
	__HitPoints = 100;
	__AttackDamage = 20;
	__EnergyPoints = 50;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called"
			<< std::endl;
}

ScavTrap::ScavTrap(ScavTrap &f) : ClapTrap(f)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	__Name = f.__Name;
	__HitPoints = f.__HitPoints;
	__EnergyPoints = f.__EnergyPoints;
	__AttackDamage = f.__AttackDamage;
}

ScavTrap &ScavTrap::operator=(ScavTrap &f)
{
	std::cout << "ScavTrap equal operator overload called" << std::endl;
	if (this != &f)
	{
		__Name = f.__Name;
		__HitPoints = f.__HitPoints;
		__EnergyPoints = f.__EnergyPoints;
		__AttackDamage = f.__AttackDamage;
	}
	return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << __Name << " now in guard mode" << std::endl;
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