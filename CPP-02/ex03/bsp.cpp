/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 07:33:06 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/07 12:42:41 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed result_abc = calculate_area(a, b, c);
	Fixed result_pab = calculate_area(point, a, b);
	Fixed result_pbc = calculate_area(point, b, c);
	Fixed result_pac = calculate_area(point, a, c);
	
	if (result_abc == -1 || result_pab == -1 || result_pbc == -1 || result_pac == -1)
		return false;
	if (result_abc == (result_pab + result_pbc + result_pac))
		return (true);
	else
		return (false);
}

Fixed calculate_area(Point a, Point b, Point c)
{
	Fixed result = a.getX() * (b.getY() - c.getY())
					+ b.getX() * (c.getY() - a.getY())
					+ c.getX() * (a.getY() - b.getY());
	if (result != 0)
		result = result / 2.0f;
	else
		return result = -1;
	if (result < 0)
		result = result * -1;
	return result;
}