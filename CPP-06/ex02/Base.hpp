/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:04:00 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 16:20:40 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


class Base
{
	public:
		virtual ~Base();
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif