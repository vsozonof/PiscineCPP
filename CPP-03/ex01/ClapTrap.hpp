/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:00:58 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 01:32:38 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string __Name;
		int __HitPoints;
		int __EnergyPoints;
		int	__AttackDamage;

	public:
		ClapTrap();
		ClapTrap(ClapTrap &f);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &f);
		ClapTrap(std::string name);
		void	announce(void);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printVal(void);
		void	setName(std::string name);
		void	setHp(unsigned int amount);
		void	setEp(unsigned int amount);
		void	setAd(unsigned int amount);
};

#endif