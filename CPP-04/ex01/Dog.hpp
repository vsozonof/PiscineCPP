/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:53:53 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 09:11:35 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain * _brain;
	
	public:
		Dog();
		Dog(std::string type);
		Dog(Dog const & src);
		~Dog();
		Dog & operator=(Dog const & src);

		virtual void makeSound() const;
};

#endif