/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:41:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/10 07:49:06 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	std::cout << "---- EX00 : Tests ----" << std::endl;
	
	ClapTrap a;
	ClapTrap b("Poulet");
	ClapTrap c(b);

	a.attack("Poulet");
	b.takeDamage(11);
	c.attack("Poisson");
	a.takeDamage(9);
	for (int i = 0; i <= 10; i++)
		a.beRepaired(1);
	a.attack("Poulet");
	
}