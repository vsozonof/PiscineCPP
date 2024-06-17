/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 07:41:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 10:48:17 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main (void)
{
	std::cout << "---- EX03 : Tests ----" << std::endl;
	
	DiamondTrap a("Poisson");

	std::cout << "HP = " << a.getHp()
			<< " EP = " << a.getEp()
				<< " AD = " << a.getAd()
					<< std::endl;

	a.whoAmI();
}