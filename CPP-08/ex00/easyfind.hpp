/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:39:43 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/27 03:32:29 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stdexcept>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
typename T::iterator easyfind (T &container, int n2)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n2);
	if (it == container.end())
		throw std::runtime_error("Number not found!");
	return it;
}

#endif