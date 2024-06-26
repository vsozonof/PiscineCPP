/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:19:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 10:01:00 by vsozonof         ###   ########.fr       */
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
	Animal ** j = new Animal*[20];

	for (int i = 0; i < 20; i++)
	{
		if (i % 2 == 0)
			j[i] = new Dog();
		else
			j[i] = new Cat();
	}

	std::cout << "\n---------------------\n" << std::endl;

	for (int i = 0; i < 20; i++)
	{
		delete j[i];
	}

	delete [] j;
}