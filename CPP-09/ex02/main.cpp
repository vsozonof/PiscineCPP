/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:09:18 by vsozonof          #+#    #+#             */
/*   Updated: 2025/02/24 19:50:35 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	checkDupes(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (argv[i])
	{
		while (argv[j])
		{
			if (atoi(argv[i]) == atoi(argv[j]) && (j != i))
				return 0;
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

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

	if (!checkDupes(argv))
	{
		std::cerr << BOLD_RED "Error:" DEFAULT << " duplicate detected"<< std::endl;
		exit(1);
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

	std::list<int> list;
	std::vector<int> vector;

	for (int i = 1; i < argc; i++)
	{
		int n = std::atoi(argv[i]);
		list.push_back(n);
		vector.push_back(n);
	}

	PmergeMe sort;
	std::cout << BOLD_YELLOW << "\n-\t\t SORTING WITH STD::LIST \t\t-" << DEFAULT << std::endl;
	sort.FordJohnson(list);

	std::cout << BOLD_YELLOW << "\n-\t\t SORTING WITH STD::VECTOR \t\t-" << DEFAULT << std::endl;
	sort.FordJohnson(vector);
	
	return 0;
}