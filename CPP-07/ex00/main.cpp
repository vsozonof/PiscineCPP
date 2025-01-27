/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:54:51 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/27 02:44:02 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Templates.hpp"

int main(void)
{
	double x = 3.14, y = 2.71;
	std::cout << "TEST 01 :" << std::endl;
	std::cout << "Before swap:" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	swap(x, y);
	std::cout << "After swap:" << std::endl;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << max(x, y) << std::endl;
	std::cout << min(x, y) << std::endl;

	std::string s1 = "hello", s2 = "world";
	std::cout << "\nTEST 02 :" << std::endl;
	std::cout << "Before swap:" << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
	swap(s1, s2);
	std::cout << "After swap:" << std::endl;
	std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
}