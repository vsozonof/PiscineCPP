/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:12:24 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/17 18:12:12 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <time.h>
#include <algorithm>
#include <iomanip>

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
		
		void	doListSort(std::list<int> &list);
		void 	doVectorSort(std::vector<int> &vector);
		
		std::list<int> merge(const std::list<int>& left, const std::list<int>& right);
		std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right);
		
	private:
		double				_time;
};

#endif
