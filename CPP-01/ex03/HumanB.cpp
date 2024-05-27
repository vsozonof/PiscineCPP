/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 03:01:56 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/27 03:28:22 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weap(NULL) {}

HumanB::~HumanB() {}

void HumanB::setWeapon(Weapon &weapon)
{
	weap = &weapon;
}

void HumanB::attack()
{
	if (!weap)
		std::cout << name << " is not armed, he can't attack !" << std::endl;
	else
		std::cout << name << " attacks with their " << weap->getType() << std::endl;
}