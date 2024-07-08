/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:59:09 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 09:24:09 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &src);
	
	public:
		~Serializer();
		Serializer &operator=(Serializer const &rhs);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif