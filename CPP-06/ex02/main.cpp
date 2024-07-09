/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 10:11:51 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/09 13:37:07 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>
int main()
{
	Base *base = generate();
	identify(base);
	identify(*base);
	delete base;

	sleep(1);

	Base *base2 = generate();
	identify(base2);
	identify(*base2);
	delete base2;

	sleep(1);

	Base *base3 = generate();
	identify(base3);
	identify(*base3);
	delete base3;
	return (0);
}