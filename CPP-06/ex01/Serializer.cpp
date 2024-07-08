/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:02:17 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 09:55:46 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// ? Constructors / Destructor / Assignation operator

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &src) { (void)src; }

Serializer::~Serializer() {}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}

// ? Serializer

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}