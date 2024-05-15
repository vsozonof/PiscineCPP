/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:10:15 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/15 08:30:33 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{	
	std::cout << "\nzombieHorde function\n" << std::endl;
	Zombie *z6 = zombieHorde(5, "horde");
	for (int i = 0; i < 5; i++)
		z6[i].announce();
	delete [] z6;
}