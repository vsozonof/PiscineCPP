/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 06:24:40 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/07 09:48:57 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::Point(const Point &f) : x(f.x), y(f.y) {}

Point &Point::operator=(const Point &f)
{
	if (this != &f)
	{
		Point temp(f);

		const_cast<Fixed&>(this->x) = temp.x;
        const_cast<Fixed&>(this->y) = temp.y;
	}
	return *this;
}

Point::~Point() {}

Fixed Point::getX()
{
	return x;
}

Fixed Point::getY()
{
	return y;
}