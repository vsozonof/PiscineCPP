/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:24 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/07 06:22:24 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <math.h>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int fixed_point;
		static const int fractional_bits = 8;
	
	public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed (const Fixed &f);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int	toInt(void) const;
		
		Fixed &operator=(const Fixed &f);
};
		
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif