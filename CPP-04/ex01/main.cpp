/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:19:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/29 21:00:54 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main()
{
	// Animal ** j = new Animal*[20];

	// for (int i = 0; i < 20; i++)
	// {
	// 	if (i % 2 == 0)
	// 		j[i] = new Dog();
	// 	else
	// 		j[i] = new Cat();
	// }

	// std::cout << "\n---------------------\n" << std::endl;

	// for (int i = 0; i < 20; i++)
	// {
	// 	delete j[i];
	// }

	// delete [] j;

	std::cout << "DOG CONSTRUCTORS" << std::endl;
	Dog d_basic;
	std::cout << "\n\nCAT CONSTRUCTORS" << std::endl;
	Cat	c_basic;
{
	std::cout << "\n\nDOG OPERATIONS" << std::endl;
	Dog tmp = d_basic;
	std::cout << "\n\nCAT OPERATIONS" << std::endl;
	Cat tmp2 = c_basic;
	std::cout << "\n\nDESTRUCTORS" << std::endl;
}
}