/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:08:48 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 10:10:38 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base * Base::generate(void)
{
	if (rand() % 3 == 0)
		return (new A);
	else if (rand() % 3 == 1)
		return (new B);
	else
		return (new C);
}