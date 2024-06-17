/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:00:58 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/17 07:47:29 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int HP;
		int EP;
		int	AD;

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
		void	setName(std::string name);
		void	setHp(unsigned int amount);
		void	setEp(unsigned int amount);
		void	setAd(unsigned int amount);
		std::string getName(void);
		int		getHp(void);
		int		getEp(void);
		int		getAd(void);
};

#endif