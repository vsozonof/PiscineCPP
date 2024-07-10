/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:15:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/10 14:11:56 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return (0);
// }

int main (void)
{
	// Span sp = Span(20000);
	// for (int i = 0; i <= 20000; i++)
	// 	sp.addNumber(i);
	
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;

	// try
	// {
	// 	sp.addNumber(9391293);
	// }
	// catch (std::exception & e)
	// {
	// 	std::cout << e.what() << std::endl;
	// }

	// Span sp2 = Span(50000);
	// for (int i = 0; i <= 50000; i++)
	// 	sp2.addNumber(rand());

	// std::cout << sp2.shortestSpan() << std::endl;
	// std::cout << sp2.longestSpan() << std::endl;
	// sp2.print_infos();
	
 	int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9, 10};
    std::vector<int> v(arr1, arr1 + 5);
    std::vector<int> v2(arr2, arr2 + 5);

    Span sp3(10);
    sp3.addManyNumber(v.begin(), v.end());
    sp3.addManyNumber(v2.begin(), v2.end());

    std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
    sp3.print_infos();
	
	return (0);
}