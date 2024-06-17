/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 07:37:10 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 09:47:46 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap constructor called"
			<< std::endl;
	setHp(100);
	setAd(30);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called"
			<< std::endl;
	setHp(100);
	setAd(30);
}

FragTrap::FragTrap(FragTrap &f)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	this->setName(f.getName());
	this->setHp(f.getHp());
	this->setEp(f.getEp());
	this->setAd(f.getAd());
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
		this->setName(f.getName());
		this->setHp(f.getHp());
		this->setEp(f.getEp());
		this->setAd(f.getAd());
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
	std::cout << "FragTrap : high-five request!" << std::endl;
}