/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:11:34 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/15 08:31:07 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie 
{
	private:
		std::string name;

	public:
		Zombie() {}
		Zombie(std::string name);
		~Zombie();
		void announce(void);
		void setName(std::string name);
};

	Zombie* zombieHorde(int N, std::string name);

#endif