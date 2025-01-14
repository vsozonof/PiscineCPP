/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:06 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/07 12:43:37 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void ) 
{
	std::cout << "\n\t---- TESTS : EX03 ----\n" << std::endl;
	std::cout << "Testing copy operator :\n" << std::endl;
	
	Point a99(55, 51);
	Point a98(999, 111);

	a99 = a98;

	std::cout << a99.getX() << " - " << a99.getY() << std::endl;

	
	std::cout << "Testing BSP function :\n" << std::endl;
	std::cout << "Test 1: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(1, 1)) << std::endl; // Expected: true
	std::cout << "Test 2: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(6, 6)) << std::endl; // Expected: false
	std::cout << "Test 3: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 2)) << std::endl; // Expected: false
	std::cout << "Test 4: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 0)) << std::endl; // Expected: false
	std::cout << "Test 5: " << bsp(Point(-3, -2), Point(0, -2), Point(-3, -6), Point(-2, -3)) << std::endl; // Expected: true
	std::cout << "Test 6: " << bsp(Point(-2, -2), Point(0, -2), Point(-3, -6), Point(-2, -3)) << std::endl; // Expected: true
	std::cout << "Test 7: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(2, 3)) << std::endl; // Expected: true
	std::cout << "Test 8: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(2, 2)) << std::endl; // Expected: false
	std::cout << "Test 9: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 5)) << std::endl; // Expected: false
	std::cout << "Test 10: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(5, 5)) << std::endl; // Expected: false
	std::cout << "Test 11: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 0)) << std::endl; // Expected: false
	std::cout << "Test 12: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(5, 0)) << std::endl; // Expected: false
	std::cout << "Test 13: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, 10)) << std::endl; // Expected: false
	std::cout << "Test 14: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(2, 2)) << std::endl; // Expected: false
	std::cout << "Test 15: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(5, 5)) << std::endl; // Expected: false
	std::cout << "Test 16: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(0, -1)) << std::endl; // Expected: false
	std::cout << "Test 17: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(1, -1)) << std::endl; // Expected: false
	std::cout << "Test 18: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(-1, -1)) << std::endl; // Expected: false
	std::cout << "Test 19: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(-1, 0)) << std::endl; // Expected: false
	std::cout << "Test 20: " << bsp(Point(0, 0), Point(5, 0), Point(0, 5), Point(-1, 1)) << std::endl; // Expected: false
	return (0);
}