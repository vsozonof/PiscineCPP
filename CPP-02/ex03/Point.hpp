/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:30:49 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/04 09:42:57 by vsozonof         ###   ########.fr       */
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
		Point &operator=(const Point &f)
		{
			if (this != &f)
				x = f.x;
			return *this;
		}
}

#endif