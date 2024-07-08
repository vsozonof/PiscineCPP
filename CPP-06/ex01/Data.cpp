/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:06:00 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 09:10:09 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// ? Constructors / Destructor / Assignation operator

Data::Data() 
{
	_id = "0";
	_name = "default";
}

Data::Data(std::string const &id, std::string const &name) : _id(id), _name(name) {}

Data::Data(Data const &src)
{
	_id = src._id;
	_name = src._name;
}

Data::~Data() {}

Data &Data::operator=(Data const &rhs)
{
	_id = rhs._id;
	_name = rhs._name;
	return (*this);
}

