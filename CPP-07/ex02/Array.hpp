/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:19:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/09 15:08:36 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template <class T>
class Array
{
	private:
		T	 			*_array;
		unsigned int	_size;
		
	public:
		Array() : _array(new T[0]), _size(0) {}
		Array(unsigned int n) : _array(new T[n]), _size(n) {}
		~Array() { delete [] _array; }
		
		Array(Array const &src) : _array(new T[src._size]), _size(src._size)
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		} 
		
		Array &operator=(Array const &rhs) 
		{
			if (this != &rhs)
			{
				delete[] _array;
				_size = rhs._size;
				_array = new T[_size];
				for (int i = 0; i < _size; i++)
					_array[i] = rhs._array[i];
			}
			return *this;
		}

		T& operator[](unsigned int i)
		{
			if (i >= _size)
				throw std::out_of_range("Index out of range");
			return _array[i];
		}

		bool operator==(Array const &rhs) const
		{
			if (_size != rhs._size)
				return false;
			for (unsigned int i = 0; i < _size; i++)
				if (_array[i] != rhs._array[i])
					return false;
			return true;
		}

		bool &operator!=(Array const &rhs) const
		{
			return !(*this == rhs);
		}
	
		unsigned int size() const { return _size; }
};

#endif