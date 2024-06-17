/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:41:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 08:44:53 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	std::cout << "---- EX01 : Tests ----" << std::endl;
	
	ScavTrap a("poisson");
	ScavTrap b("Victor");

	std::cout << "HP = " << a.getHp()
				<< " EP = " << a.getEp()
					<< " AD = " << a.getAd()
						<< std::endl;
	

	a.attack("Victor");
	a.attack("Victor");
	a.attack("Victor");
	a.attack("Victor");
	a.attack("Victor");
	b.takeDamage(100);
	a.guardGate();

	ScavTrap c(b);
	
	std::cout << "HP = " << b.getHp()
				<< " EP = " << b.getEp()
					<< " AD = " << b.getAd()
						<< std::endl;
	c = a;
	std::cout << "HP = " << a.getHp()
			<< " EP = " << a.getEp()
				<< " AD = " << a.getAd()
					<< std::endl;
	
}