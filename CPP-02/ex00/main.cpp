/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:06 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/04 06:25:42 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	std::cout << "\n\t---- TESTS : EX00 ----\n" << std::endl;
	std::cout << "Creating objects with no value\n" << std::endl;
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << "\nPrinting objects fixed-point values\n" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << "\n" << std::endl;

	a.setRawBits(42);
	b.setRawBits(42);
	c.setRawBits(42);

	std::cout << "\n" << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << "\n" << std::endl;

	return (0);
}