/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:24 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/04 07:00:15 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int fixed_point;
		static const int fractional_bits = 8;
	
	public:
		Fixed();
		Fixed (const Fixed &f);
		~Fixed();
		Fixed &operator=(const Fixed &f)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this != &f)
				this->fixed_point = f.fixed_point;
			return *this;
		}
		int getRawBits(void) const;
		void setRawBits(int const raw);
};

#endif