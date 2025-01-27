/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:04:18 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/26 23:13:15 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T> void iter(T *arr, size_t len, void (*f)(T const &))
{
	for (size_t i = 0; i < len; i++)
	{
		f(arr[i]);
	}
}

#endif