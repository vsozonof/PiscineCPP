/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:11:11 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 08:52:44 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


// ? Constructors / Destructor / Assignation operator

ScalarConverter::ScalarConverter(std::string const &str)
{
	(void)str;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	(void)src;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return (*this);
}

// ? Converter

void ScalarConverter::convert(std::string const &str)
{
	ScalarConverter sc(str);
	sc.toChar(str);
	sc.toInt(str);
	sc.toFloat(str);
	sc.toDouble(str);
}

void ScalarConverter::toChar(std::string const &str)
{
	char c = std::atoi(str.c_str());
	
	if (c >= 32 && c <= 126)
		std::cout << "char: '" << c << "'" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cerr << "Error: invalid char" << std::endl;
}

void ScalarConverter::toInt(std::string const &str)
{
	char* end;
    long val = std::strtol(str.c_str(), &end, 10);
 	
	if (str.empty() || (val == 0 && str[0] != '0')
		|| val > std::numeric_limits<int>::max() 
		|| val < std::numeric_limits<int>::min())
        std::cerr << "Error: invalid int" << std::endl;
    else
        std::cout << "Int: " << static_cast<int>(val) << std::endl;
}

void ScalarConverter::toFloat(std::string const &str)
{
	char* end;
	float val = std::strtof(str.c_str(), &end);
	
	if (str == "nanf" || str == "+inff" || str == "-inff")
		std::cout << "Float: " << str << std::endl;
	else if (str.empty() || (val == 0 && str[0] != '0')
		|| val > std::numeric_limits<float>::max() 
		|| val < std::numeric_limits<float>::min())
		std::cerr << "Error: invalid float" << std::endl;
	else
		std::cout << "Float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;
}

void ScalarConverter::toDouble(std::string const &str)
{
	char* end;
	double val = std::strtod(str.c_str(), &end);
	
	
	if (str == "nan" || str == "+inf" || str == "-inf")
		std::cout << "Double: " << str << std::endl;
	else if (str.empty() || (val == 0 && str[0] != '0')
		|| val > std::numeric_limits<double>::max() 
		|| val < std::numeric_limits<double>::min())
		std::cerr << "Error: invalid double" << std::endl;
	else
		std::cout << "Double: " << std::fixed << std::setprecision(1) << val << std::endl;
}