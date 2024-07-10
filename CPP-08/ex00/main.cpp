/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:39:34 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/10 12:59:57 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

	std::vector<int>::iterator it = easyfind(vec, 3);
	if (it != vec.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::list<int>::iterator it2 = easyfind(lst, 30);
	if (it2 != lst.end())
		std::cout << "Found: " << *it2 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	std::list<int>::iterator it3 = easyfind(lst, 100);
	if (it3 != lst.end())
		std::cout << "Found: " << *it3 << std::endl;
	else
		std::cout << "Not found" << std::endl;

	return 0;
}