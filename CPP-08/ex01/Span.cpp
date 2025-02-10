/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 13:09:25 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/31 09:57:18 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0), _v(0) {}

Span::Span(unsigned int n) : _n(n), _v(0) {}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span() {}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_v = rhs._v;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (_v.size() <= _n)
		_v.push_back(n);
	else
		throw std::out_of_range("Span is full");
}

int Span::shortestSpan()
{
	if (_v.size() < 2)
		throw std::out_of_range("Not enough span elements, action impossible");
	std::sort(_v.begin(), _v.end());
	int minSpan = std::numeric_limits<int>::max();
	for (size_t i = 1; i < _v.size(); i++)
	{
        int span = _v[i] - _v[i - 1];
        minSpan = std::min(minSpan, span);
	}
	return minSpan;
}

int Span::longestSpan()
{
	if (_v.size() < 2)
		throw std::out_of_range("Not enough span elements, action impossible");
	std::sort(_v.begin(), _v.end());
	return (_v[_v.size() - 1] - _v[0]);
}

void Span::print_infos()
{
	std::cout << "/n~~ Printing Span Informations ~~";
	std::cout << "- Max Span elements : " << _n << std::endl;
	std::cout << "- Number of Span elements : " << _v.size() << std::endl;
	std::cout << "- Smallest number found : " << _v[0] << std::endl;
	std::cout << "- 2nd Smallest number found : " << _v[1] << std::endl;
	std::cout << "- Largest number found : " << _v[_v.size() - 1] << std::endl;
	std::cout << "- 2nd Largest number found : " << _v[_v.size() - 2] << std::endl;
}