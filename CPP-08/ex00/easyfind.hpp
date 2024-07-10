/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:39:43 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/10 12:59:31 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>


bool BadNumber(void)
{
	std::cout << "Number not found" << std::endl;
	return false;
}

template <typename T>
typename T::iterator easyfind (T &container, int n2)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n2);
	if (it == container.end())
		BadNumber();
	return it;
}

#endif