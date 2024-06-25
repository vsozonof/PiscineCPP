/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:41:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 01:56:21 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main (void)
{
	std::cout << "----\tEX03 : Tests\t----\n" << std::endl;
	std::cout << "----\tDiamondTrap\t----" << std::endl;
	std::cout << "----\t01 - Constructors\t----\n" << std::endl;

	DiamondTrap a;
	DiamondTrap b("Poulet");

	std::cout << "\n----\tPrinting values\t----\n" << std::endl;
	b.printVal();
	std::cout << std::endl;
	b.attack("test");
	std::cout << std::endl;
	b.printVal();
	std::cout << std::endl;
	std::cout << "----\tCopy constructor\t----\n" << std::endl;
	DiamondTrap c(b);
	std::cout << std::endl;
	c.printVal();

	std::cout << "\n----\tAttacking / Repairing\t----\n" << std::endl;
	a.attack("Poulet");
	b.takeDamage(101);
	c.attack("Poisson");
	a.takeDamage(9);
	for (int i = 0; i <= 101; i++)
		a.beRepaired(1);

	std::cout << "\n----\tAttacking / Repairing with no energy\t----\n" << std::endl;
	a.attack("Poulet");
	a.beRepaired(1);

	std::cout << "\n----\tWho Are We ?\t----\n" << std::endl;
	a.whoAmI();
	b.whoAmI();

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