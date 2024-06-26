/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:10:15 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/15 08:29:02 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
		std::cout << "EX00 - TESTS" << std::endl;
	std::cout << "ZOMBIE OBJECT CREATION\n" << std::endl;
	Zombie z1("z1");
	z1.announce();

	std::cout << "\nrandomChump function\n" << std::endl;
	randomChump("z2");
	randomChump("z3");
	randomChump("z4");
	
	std::cout << "\nnewZombie function\n" << std::endl;
	Zombie *z5 = newZombie("z5");
	z5->announce();
	delete z5;
}