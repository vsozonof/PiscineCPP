/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:13:17 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 16:28:33 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base * generate()
{
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
    try
	{
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
	catch (std::exception&) {}

    try
	{
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    } 
	catch (std::exception&) {}

    try 
	{
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    } 
	catch (std::exception&) {}
}