/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:12:24 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/15 09:33:16 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <time.h>
#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>

#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define DEFAULT "\033[0m"

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		PmergeMe &operator=(const PmergeMe &rhs);

		void	mergeSort(std::list<int> &list);
		void	mergeSort(std::vector<int> &vector);
		double	getTime() const;

	private:
		double				_time;
};

#endif
