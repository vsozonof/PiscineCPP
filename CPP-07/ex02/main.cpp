/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:17:36 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/09 15:18:48 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Array.hpp"
#include <cstdlib>
#include <string>

int main(int, char**)
{
	Array<int> intArr(5);
	Array<int> intArr2(5);
	Array<std::string> strArr(5);
	
	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << intArr[i] << " [";
		std::cout << strArr[i] << "]" << std::endl;
	}

	for (unsigned int i = 0; i < 5; i++)
	{
		intArr[i] = i;
		strArr[i] = '0' + i;
	}

	std::cout << "intArr == intArr2: " << (intArr == intArr2) << std::endl;

	for (unsigned int i = 0; i < 5; i++)
	{
		std::cout << intArr[i] << " ";
		std::cout << strArr[i] << std::endl;
	}

	try
	{
		intArr[5] = 5;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << intArr.size() << " " << strArr.size() << std::endl;

	return 0;
}