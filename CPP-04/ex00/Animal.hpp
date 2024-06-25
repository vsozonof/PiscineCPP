/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:11:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 02:19:49 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string __type;

	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const & src);
		virtual ~Animal();
		Animal & operator=(Animal const & src);

		std::string getType() const;
		virtual void makeSound();
};

#endif