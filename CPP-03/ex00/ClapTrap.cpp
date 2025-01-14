/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:00:54 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 01:24:33 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "Default constructor called" << std::endl;
	__Name = "Norminet";
	__HitPoints = 10;
	__EnergyPoints = 10;
	__AttackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Name constructor called" << std::endl;
	__Name = name;
	__HitPoints = 10;
	__EnergyPoints = 10;
	__AttackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &f)
{
	std::cout << "Copy constructor called" << std::endl;
	__Name = f.__Name;
	__HitPoints = f.__HitPoints;
	__EnergyPoints = f.__EnergyPoints;
	__AttackDamage = f.__AttackDamage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f)
{
	std::cout << "Equal operator overload called" << std::endl;
	if (this != &f)
	{
		__Name = f.__Name;
		__HitPoints = f.__HitPoints;
		__EnergyPoints = f.__EnergyPoints;
		__AttackDamage = f.__AttackDamage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (__EnergyPoints > 0 && __HitPoints > 0)
	{
		std::cout << "ClapTrap: " << __Name 
					<< " attacks " << target 
						<< ", causing " << __AttackDamage 
							<< " points of damage!" << std::endl;
		__EnergyPoints--;
	}
	else
		std::cout << "ClapTrap: " << __Name
					<< " can't attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap: " << __Name 
				<< " was attacked and lost " 
					<< amount << " hit points!" << std::endl;
	__HitPoints -= amount;
	if (__HitPoints <= 0)
		std::cout << "ClapTrap: " << __Name 
					<< " died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (__EnergyPoints > 0 && __HitPoints > 0)
	{
		std::cout << "ClapTrap: " << __Name 
						<< ", healing " << amount 
							<< " hit points!" << std::endl;
		__EnergyPoints--;
	}
	else
		std::cout << "ClapTrap: " << __Name
					<< " can't repair his self!" << std::endl;
}

void	ClapTrap::printVal(void)
{
	std::cout << "Name: " << __Name << std::endl;
	std::cout << "HitPoints: " << __HitPoints << std::endl;
	std::cout << "EnergyPoints: " << __EnergyPoints << std::endl;
	std::cout << "AttackDamage: " << __AttackDamage << std::endl;
}