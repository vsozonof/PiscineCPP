/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:06:03 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 09:09:51 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class Data
{
	private:
		std::string _id;
		std::string _name;

	public:
		Data();
		Data(std::string const &id, std::string const &name);
		Data(Data const &src);
		~Data();
		Data &operator=(Data const &rhs);
};

#endif