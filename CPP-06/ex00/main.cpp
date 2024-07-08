/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:13:48 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 08:55:04 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main (int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./scalar_converter <string>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	ScalarConverter::convert("'a'");
    ScalarConverter::convert("65");
    ScalarConverter::convert("3.14f");
    ScalarConverter::convert("123.456");

    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inff");
    ScalarConverter::convert("-inf");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nan");

    ScalarConverter::convert("abc");
    ScalarConverter::convert("1.2.3");
    ScalarConverter::convert("invalid");
    ScalarConverter::convert("");
	return (0);
}