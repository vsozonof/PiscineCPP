/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:00 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 10:10:53 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class Base
{
	public:
		Base() {};
		virtual ~Base() {};
		Base *generate(void);
		void identfy(Base *p);
		void identfy(Base &p);
};

#endif