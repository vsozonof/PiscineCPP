/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:32:56 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/27 03:29:12 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

int main (void)
{
	std::cout << "Human A TESTS\n" << std::endl;
	Weapon club = Weapon("club");
	HumanA bob("bob", club);
	bob.attack();
	club.setType("cricket bat");
	bob.attack();
	std::cout << club.getType() << std::endl;

	std::cout << "\nHuman B TESTS\n" << std::endl;
	club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
}