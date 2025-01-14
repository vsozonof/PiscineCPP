/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 07:37:10 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 01:59:47 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called"
			<< std::endl;
	__HitPoints = 100;
	__EnergyPoints = 100;
	__AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called"
			<< std::endl;
	__HitPoints = 100;
	__EnergyPoints = 100;
	__AttackDamage = 30;
}

FragTrap::FragTrap(FragTrap &f) : ClapTrap(f)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	__Name = f.__Name;
	__HitPoints = f.__HitPoints;
	__EnergyPoints = f.__EnergyPoints;
	__AttackDamage = f.__AttackDamage;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called"
		<< std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &f)
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

void FragTrap::announce(void)
{
	std::cout << "FragTrap : ";
}

void FragTrap::attack(const std::string& target)
{
	FragTrap::announce();
	ClapTrap::attack(target);
}

void FragTrap::takeDamage(unsigned int amount)
{
	FragTrap::announce();
	ClapTrap::takeDamage(amount);
}

void FragTrap::beRepaired(unsigned int amount)
{
	FragTrap::announce();
	ClapTrap::beRepaired(amount);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap : " << __Name << " high-five requested!" << std::endl;
}