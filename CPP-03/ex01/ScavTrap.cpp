/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 08:16:59 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/10 10:14:23 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() 
{
	std::cout << "ScavTrap constructor called"
				<< std::endl;	
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called"
				<< std::endl;	
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called"
			<< std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f)
{
	std::cout << "ScavTrap equal operator overload called" << std::endl;
	if (this != &f)
		*this = f;
	return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: now in guard mode" << std::endl;
}

void ScavTrap::attack(std::string target)
{
	std::cout << "ScavTrap : ";
	ClapTrap::attack(target);
}