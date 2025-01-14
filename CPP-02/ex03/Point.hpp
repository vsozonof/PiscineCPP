/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:49 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/07 09:51:28 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point 
{
	private:
		const Fixed x;
		const Fixed y;
	
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &f);
		~Point();
		Point &operator=(const Point &f);
		Fixed getY();
		Fixed getX();
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
Fixed calculate_area(Point a, Point b, Point c);

#endif