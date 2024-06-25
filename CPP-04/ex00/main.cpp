/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:19:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/25 02:21:10 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int main()
{
	std::cout << "-- Constructors --" << std::endl;
	Animal a;
	a.makeSound();

	std::cout << "Destructor" << std::endl;
}