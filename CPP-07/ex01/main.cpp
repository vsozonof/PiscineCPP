/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:03:52 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/09 14:14:49 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void	print_char(char const &c)
{
	std::cout << c << std::endl;
}

void print_int(int const &i)
{
	std::cout << i << std::endl;
}

int main(void)
{

	char str[] = "hello world ! ";
	int arr[] = {1, 2, 3, 4, 5};

	iter(str, 14, print_char);
	iter(arr, 5, print_int);
	
	return (0);
}