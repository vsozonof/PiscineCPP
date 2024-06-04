/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:38:06 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/04 09:07:35 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) 
{
	std::cout << "\n\t---- TESTS : EX02 ----\n" << std::endl;

	std::cout << "\nTESTING ADDITION\n"<< std::endl;
	Fixed const b1( Fixed( 5.05f ) + Fixed( 2 ) );
	Fixed const b2( Fixed( 10 ) + Fixed( 2 ) );
	Fixed const b3( Fixed( 1 ) + Fixed( 2 ) );
	
	std::cout << "b1 = " << b1 << "\nb2 = " << b2 << "\nb3 = " << b3 << std::endl;

	std::cout << "\nTESTING SOUSTRACTION\n" << std::endl;
	Fixed const c1( Fixed( 5.05f ) - Fixed( 2 ) );
	Fixed const c2( Fixed( 10) - Fixed( 2 ) );
	Fixed const c3( Fixed( 1 ) - Fixed( 2 ) );

	std::cout << "c1 = " << c1 << "\nc2 = " << c2 << "\nc3 = " << c3 << std::endl;
	
	std::cout << "\nTESTING MULTIPLICATION\n"<< std::endl;
	Fixed const e1( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const e2( Fixed( 10 ) * Fixed( 2 ) );
	Fixed const e3( Fixed( 9 ) * Fixed( 2 ) );

	std::cout << "e1 = " << e1 << "\ne2 = " << e2 << "\ne3 = " << e3 << std::endl;
	
	std::cout << "\nTESTING DIVISION\n" << std::endl;
	std::cout << "VALID DIVISION\n" << std::endl;
	Fixed const d1( Fixed( 5.05f ) / Fixed( 2 ) );
	Fixed const d2( Fixed( 30 ) / Fixed( 2 ) );
	Fixed const d3( Fixed( 3 ) / Fixed( 2 ) );

	std::cout << "d1 = " << d1 << "\nd2 = " << d2 << "\nd3 = " << d3 << std::endl;

	std::cout << "INVALID DIVISION\nWill set value to zero by default\n" << std::endl;
	
	Fixed const f( Fixed( 0 ) / Fixed( 2 ) );
	Fixed const g( Fixed( 5.05f ) / Fixed( 0 ) );

	std::cout << "f = " << f << "\ng = " << g << std::endl;
	
	std::cout << "\nTESTING INCREMENTATION AND DECREMENTATION\n" << std::endl;
	
	Fixed h(1.05f);
	std::cout << "h++ -> " << h++ << "\n++h -> " << ++h  << "\nh-- -> " << h-- << "\n--h -> " << --h << std::endl;
	
	std::cout << "\nTESTING MIN MAX FUNCTIONS\n" << std::endl;

	Fixed const a1(55);
	Fixed const a2(55.05f);
	Fixed a3(12);
	Fixed a4(1555);

	std::cout << Fixed::max( a1, a2 ) << std::endl;
	std::cout << Fixed::min( a1, a2 ) << std::endl;
	std::cout << Fixed::max( a3, a4 ) << std::endl;
	std::cout << Fixed::min( a3, a4 ) << std::endl;

	return (0);
}