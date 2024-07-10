/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:01:53 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/10 14:08:10 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <limits>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _v;
		Span();
		
	public:
		Span(unsigned int n);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const & rhs);
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void print_infos();
		
		template <typename InputIterator>
		void addManyNumber(InputIterator begin, InputIterator end)
		{
			size_t distance = std::distance(begin, end);
			if (_v.size() + distance <= _n)
				_v.insert(_v.end(), begin, end);
			else
				throw std::out_of_range("Span is full");
		}
};


#endif