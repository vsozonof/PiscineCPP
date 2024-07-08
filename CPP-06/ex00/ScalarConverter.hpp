/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 06:55:18 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 08:17:08 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class ScalarConverter
{
	private:
		ScalarConverter(std::string const &str);
		ScalarConverter(ScalarConverter const &src);
	
	public:
		~ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		static void convert(std::string const &str);
		void toChar(std::string const &str);
		void toInt(std::string const &str);
		void toFloat(std::string const &str);
		void toDouble(std::string const &str);
};



#endif 