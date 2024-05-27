/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 03:32:55 by vsozonof          #+#    #+#             */
/*   Updated: 2024/05/27 07:13:01 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int	main (int argc, char **argv)
{
	if (argc != 4)
		return (std::cout << "Error: not enough arguments." << std::endl, 1);

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (filename.empty() || s1.empty())
		return (std::cout << "Error: Invalid parameters detected." << std::endl, 1);

	std::ifstream file;
	file.open(filename.data());

	if (!file.is_open())
		return (std::cout << "Error: cannot open the given file." << std::endl, 1);

	std::string content;
	std::string line;

	while (std::getline(file, line))
		content += line + '\n';

	file.close();

	std::size_t pos;

	while (42)
	{
		pos = content.find(s1);
		if (pos == std::string::npos)
			break ;
		else
		{
			content.erase(pos, s1.size());
			content.insert(pos, s2);
		}
	}

	std::cout << "Resultat : \n" << content << std::endl;
}