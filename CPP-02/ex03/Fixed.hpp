/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:24 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/07 11:30:00 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include <cstdlib>

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
		bool operator< (const Fixed& n2) const;
		bool operator<= (const Fixed& n2) const;
		bool operator> (const Fixed& n2) const;
		bool operator>= (const Fixed& n2) const;
		bool operator== (const Fixed& n2) const;
		bool operator!= (const Fixed& n2) const;
		
		Fixed operator+ (const Fixed& n2) const;
		Fixed operator- (const Fixed& n2) const;
		Fixed operator* (const Fixed& n2) const;
		Fixed operator/ (const Fixed& n2) const;

		Fixed& operator++ (); 
		Fixed operator++(int);
		Fixed& operator-- ();
		Fixed operator--(int);
		static Fixed& min(Fixed& n1, Fixed& n2)
		{
			if (n1 < n2)
				return (n1);
			else
				return (n2);
		}
		static const Fixed& min(const Fixed& n1, const Fixed& n2)
		{
			if (n1 < n2)
				return (n1);
			else
				return (n2);
		}

		static Fixed& max(Fixed &n1, Fixed &n2)
		{
			if (n1 < n2)
				return (n2);
			else
				return (n1);
		}

		static const Fixed& max(const Fixed& n1, const Fixed& n2)
		{
			if (n1 < n2)
				return (n1);
			else
				return (n2);
		}
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif