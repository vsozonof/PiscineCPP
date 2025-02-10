/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:15:04 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/31 19:44:30 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int genRandomNumber ()
{
	int n = std::rand() % 10000000;
	return (n);
}

int main()
{

	std::cout << "~~~ Basic Tests ~~~" << '\n';
	std::cout << "Testing 10 integers" << '\n';
	
	Span sp = Span(10);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(10);
	sp.addNumber(2);
	sp.addNumber(999);
	sp.addNumber(1);
	sp.addNumber(6);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


	std::cout << "\nTesting 50,000 integers" << '\n';

	Span bSp = Span(50000);
	
	std::vector<int> v_big;
	std::srand(std::time(0));

	for (int i = 0; i < 50000; i++)
	{
		int n = genRandomNumber();
		v_big.push_back(n);
	}
	std::vector<int>::const_iterator begin = v_big.begin();
	std::vector<int>::const_iterator end = v_big.end();

	bSp.addManyNumber(begin, end);

	std::cout << bSp.shortestSpan() << '\n';
	std::cout << bSp.longestSpan() << '\n';
		
	return (0);
}
