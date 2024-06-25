/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:41:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 01:44:08 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	std::cout << "----\tEX01 : Tests\t----\n" << std::endl;
	std::cout << "----\tScavTrap\t----" << std::endl;
	std::cout << "----\t01 - Constructors\t----\n" << std::endl;

	ScavTrap a;
	ScavTrap b("Poulet");

	std::cout << "\n----\tPrinting values\t----\n" << std::endl;
	b.printVal();
	std::cout << std::endl;
	b.attack("test");
	std::cout << std::endl;
	b.printVal();
	std::cout << std::endl;
	std::cout << "----\tCopy constructor\t----\n" << std::endl;
	ScavTrap c(b);
	std::cout << std::endl;
	c.printVal();

	std::cout << "\n----\tAttacking / Repairing\t----\n" << std::endl;
	a.attack("Poulet");
	b.takeDamage(101);
	c.attack("Poisson");
	a.takeDamage(9);
	for (int i = 0; i <= 50; i++)
		a.beRepaired(1);

	std::cout << "\n----\tAttacking / Repairing with no energy\t----\n" << std::endl;
	a.attack("Poulet");
	a.beRepaired(1);

	std::cout << "\n----\tGuard Gate Keeper mode\t----\n" << std::endl;
	a.guardGate();
	b.guardGate();

	std::cout << "\n----\tEqual operator overload\t----\n" << std::endl;
	c = a;
	c.attack("Poulet");
	c.beRepaired(1);

	std::cout << "\n----\tPrinting values\t----\n" << std::endl;
	std::cout << "A" << std::endl;
	a.printVal();
	std::cout << "\nB" << std::endl;
	b.printVal();
	std::cout << "\nC" << std::endl;
	c.printVal();
	std::cout << "\n----\tDestructor\t----\n" << std::endl;
}