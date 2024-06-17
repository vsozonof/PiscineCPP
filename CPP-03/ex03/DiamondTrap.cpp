/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 09:00:55 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 10:50:19 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	: ClapTrap("Norminet_clap_name"), FragTrap("Norminet_clap_name"), ScavTrap("Norminet_clap_name")
{
	std::cout << "DiamondTrap constructor called"
			<< std::endl;
	name = "Norminet";
}

DiamondTrap::DiamondTrap(std::string name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap name constructor called"
		<< std::endl;
	this->name = name;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructed" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &f) : FragTrap(f), ScavTrap(f)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	name = f.name;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &f)
{
	std::cout << "DiamondTrap equal operator overload called" << std::endl;
	if (this != &f)
	{
		this->setName(f.getName());
		this->setHp(f.getHp());
		this->setEp(f.getEp());
		this->setAd(f.getAd());
		name = f.name;
	}
	return *this;
}

void DiamondTrap::announce(void)
{
	std::cout << "DiamondTrap : ";
}

void DiamondTrap::attack(const std::string& target)
{
	DiamondTrap::announce();
	ScavTrap::attack(target);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	DiamondTrap::announce();
	ClapTrap::takeDamage(amount);
}

void DiamondTrap::beRepaired(unsigned int amount)
{
	DiamondTrap::announce();
	ClapTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Im DiamondTrap " << name << " !" << std::endl;
	std::cout << "My ClapTRap name is : " << getName() << std::endl;
}