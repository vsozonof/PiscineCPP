/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:17 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/04 09:23:40 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "math.h"

Fixed::Fixed()
{
	this->fixed_point = 0;
}

Fixed::Fixed(const int n)
{
	this->fixed_point = n << fractional_bits;
}

Fixed::Fixed(const float n)
{
	this->fixed_point = roundf(n * (1 << fractional_bits));
}

Fixed::Fixed(const Fixed &f)
{
	this->fixed_point = f.fixed_point;
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

float Fixed::toFloat (void) const
{
    return static_cast<float>(fixed_point) / (1 << fractional_bits);
}

int Fixed::toInt (void) const
{
	return fixed_point >> fractional_bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) 
{
    os << fixed.toFloat();
    return os;
}

bool Fixed::operator< (const Fixed& n2) const
{
	if (this->getRawBits() < n2.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator<= (const Fixed& n2) const
{
	if (this->getRawBits() <= n2.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator> (const Fixed& n2) const
{
	if (this->getRawBits() > n2.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator>= (const Fixed& n2) const
{
	if (this->getRawBits() >= n2.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator== (const Fixed& n2) const
{
	if (this->getRawBits() == n2.getRawBits())
		return true;
	else
		return false;
}

bool Fixed::operator!= (const Fixed& n2) const
{
	if (this->getRawBits() != n2.getRawBits())
		return true;
	else
		return false;
}

Fixed Fixed::operator+ (const Fixed& n2) const
{
	return Fixed(((float)fixed_point / 256) + ((float)n2.fixed_point / 256));
}

Fixed Fixed::operator- (const Fixed& n2) const
{
	return Fixed(((float)fixed_point / 256) - ((float)n2.fixed_point / 256));
}

Fixed Fixed::operator* (const Fixed& n2) const
{
	return Fixed(((float)fixed_point / 256) * ((float)n2.fixed_point / 256));
}

Fixed Fixed::operator/ (const Fixed& n2) const
{
	if (fixed_point == 0 || n2.fixed_point == 0)
		return Fixed();
	return Fixed(((float)fixed_point / 256) / ((float)n2.fixed_point / 256));
}

Fixed& Fixed::operator++ ()
{
	this->fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	++fixed_point;
	return temp;
}

Fixed& Fixed::operator-- ()
{
	this->fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	--fixed_point;
	return temp;
}

