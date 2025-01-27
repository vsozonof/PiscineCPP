/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:52 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/27 02:47:03 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void	print_char(char const &c)
{
	std::cout << c;
}

void print_int(int const &i)
{
	std::cout << i;
}

int main(void)
{
	char str[] = "hello world ! ";
	int arr[] = {1, 2, 3, 4, 5};


	std::cout << "Basic Tests (full length)" << std::endl;
	iter(str, 14, print_char);
	std::cout << std::endl;
	iter(arr, 5, print_int);
	std::cout << std::endl;

	std::cout << "\nBasic Tests (full length)" << std::endl;
	iter(str, 55, print_char);
	std::cout << std::endl;
	iter(arr, 55, print_int);
	std::cout << std::endl;
	
	
	return (0);
}