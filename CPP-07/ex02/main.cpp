/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:17:36 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/27 02:50:30 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include "Array.hpp"
#include <cstdlib>
#include <string>

int main() {
	std::cout << "- TESTS -\n" << std::endl;
    try
	{
		std::cout << "| Empty array tests |" << std::endl;
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
		std::cout << "emptyArray[3] = " << emptyArray[3] << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
	
	try
	{
		std::cout << "\n| Normal array tests |\n" << std::endl;
		Array<std::string> strArray(5);

		for (unsigned int i = 0; i < 5; i++)
			strArray[i] = "Hello world";
		
		for (unsigned int i = 0; i < 5; i++) 
        	std::cout << "strArray[" << i << "] = " << strArray[i] << std::endl;

		std::cout << "\n| Deep Copy tests |\n" << std::endl;

		std::cout << "\n| Equal operator tests |\n" << std::endl;
		Array<std::string> newStrArray(1);
		std::cout << "newStrArray[0] = " << newStrArray[0] << std::endl;
		std::cout << "strArray[1] = " << strArray[1] << std::endl;
		
		newStrArray[0] = strArray[1];
		std::cout << "newStrArray[0] = " << newStrArray[0] << std::endl;

		newStrArray[0] = "Poisson au poulet";
		std::cout << "\nAfter modification of newStrArray\nnewStrArray[0] = " << newStrArray[0] << std::endl;
		std::cout << "strArray[1] = " << strArray[1] << std::endl;

		strArray[1] = "Vive les chats!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
		std::cout << "\nAfter modification of strArray\nstrArray[1] = " << strArray[1] << std::endl;
		std::cout << "newStrArray[0] = " << newStrArray[0] << std::endl;

		std::cout << "\n| Copy construction tests |\n" << std::endl;
		Array<std::string> copyArray(newStrArray);
		std::cout << "newStrArray[0] = " << newStrArray[0] << std::endl;
		std::cout << "copyArray[0] = " << copyArray[0] << std::endl;

		newStrArray[0] = "6666";
		copyArray[0] = "99";
		std::cout << "\nAfter Modification of newStrArray\nnewStrArray[0] = " << newStrArray[0] << std::endl;
		std::cout << "\nAfter Modification of copyArray\ncopyArray[0] = " << copyArray[0] << std::endl;
        std::cout << "newStrArray size: " << newStrArray.size() << std::endl;
        std::cout << "newStrArray size: " << strArray.size() << std::endl;

        std::cout << "\n| Equality and Inequality tests |\n" << std::endl;
        Array<std::string> equalArray(strArray);
        Array<std::string> unequalArray(5);
        unequalArray[0] = "Different";

        std::cout << "strArray == equalArray: " << (strArray == equalArray ? "True" : "False") << std::endl;
        std::cout << "strArray != unequalArray: " << (strArray != unequalArray ? "True" : "False") << std::endl;
    }
	catch (const std::exception &e)
	{
        std::cout << "Caught exception: " << e.what() << std::endl;
	}
    return 0;
}
