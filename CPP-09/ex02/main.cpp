/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:09:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/15 12:42:50 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

void	checkArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		std::string arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!isdigit(arg[j]))
			{
				std::cerr << BOLD_RED "Error:" DEFAULT << " invalid argument"<< std::endl;
				exit(1);
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << BOLD_YELLOW "Usage: " << DEFAULT "./ex02 n1 n2 ..." << std::endl;
		return 1;
	}
	checkArgs(argc, argv);

	PmergeMe pm;

	std::list<int> list;
	std::vector<int> vector;

	for (int i = 1; i < argc; i++)
	{
		int n = std::atoi(argv[i]);
		list.push_back(n);
		vector.push_back(n);
	}

	pm.mergeSort(list);
	// pm.mergeSort(vector);

	std::cout << "OK" << std::endl;
	return 0;
}