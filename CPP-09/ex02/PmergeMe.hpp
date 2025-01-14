/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:12:24 by vsozonof          #+#    #+#             */
/*   Updated: 2025/01/14 20:50:57 by vsozonof         ###   ########.fr       */
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
		~PmergeMe();

		template <typename Container>
		void	FordJohnson(Container &cont);		
		
	private:
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &rhs);
		double				_time;

		template <typename Container>
		Container	doSort(Container &cont);
		
		template <typename Container>
		void	doPairAndCompare(Container &cont, Container &Max, Container &Min, int size);
		
		template <typename Container>
		void 	doRecursiveMergeSort(Container &Max);
		
		template <typename Container>
		Container merge (const Container &left, const Container &right);
		
		template <typename Container>
		void	doFindAndMoveSmallest(Container &cont, Container &Min);

		template <typename Container>
		void	doFindInsertionOrder(Container &to_insert, Container &Min);

		template <typename Container>
		void 	doInsertionAndBinarySearch(Container &to_insert, Container &Max);
		
		template <typename Container>
		void	doSearchPositionAndInsert(Container &Max, int n);
};

template <typename Container>
void PmergeMe::FordJohnson(Container &cont)
{
	std::cout << "Before sorting: ";
	typename Container::iterator it = cont.begin();
	for (int i = 0; i <= 9; i++)
	{
		std::cout << "[" << *it << "] ";
		it++;
	}
	std::cout << "[...]";

	clock_t start, end;
	start = clock();

	cont = doSort(cont);

	end = clock();
	double dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(7) << "\nTime needed to sort " << cont.size() << " integers : " << dif << " seconds" << std::endl;

	std::cout << "After sorting:  ";
	it = cont.begin();
	for (int i = 0; i <= 9; i++)
	{
		std::cout << "[" << *it << "] ";
		it++;
	}
	std::cout << "[...]\n" << std::endl;
	// for (typename Container::iterator full_it = cont.begin(); full_it != cont.end(); full_it++)
	// {
	// 	std::cout << "[" << *full_it << "] ";
	// 	full_it++;
	// }
}

template <typename Container>
Container PmergeMe::doSort(Container &cont)
{
	int size = cont.size();
	if (size <= 1)
		return cont;
		
	Container Max;
	Container Min;
	Container toInsert;

	// Etape 1: Pair and compare
	doPairAndCompare(cont, Max, Min, size);

	// Etape 2: Recursive merge sort
	doRecursiveMergeSort(Max);

	// Etape 3: Find and move smallest number
	doFindAndMoveSmallest(Max, Min);

	// Etape 4: Find insertion order
	doFindInsertionOrder(toInsert, Min);

	// Etape 5: Insertion and binary search
	doInsertionAndBinarySearch(toInsert, Max);

	return Max;
}

template <typename Container>
void PmergeMe::doPairAndCompare(Container &cont, Container &Max, Container &Min, int size)
{
	typename Container::iterator it = cont.begin();
	typename Container::iterator it2 = cont.begin();
	typename Container::iterator end = cont.end();
	it2++, end--;

	for (int i = 0; i < size ; i++)
	{
		if (*it == *end && size % 2 != 0)
		{
			Min.push_back(*it);
			break;
		}
		
		if (*it > *it2)
		{
			Max.push_back(*it);
			Min.push_back(*it2);
		}
		else
		{
			Max.push_back(*it2);
			Min.push_back(*it);
		}
		
		if (*it2 == *end && size % 2 == 0)
			break;

		it++, it++;
		it2++, it2++;
	}
}

template <typename Container>
void PmergeMe::doRecursiveMergeSort(Container &Max)
{
	int size = Max.size();
	if (size <= 1)
		return;
		
	Container left;
	Container right;

	int middle = (size + 1) / 2;

	for (int i = 0; i < middle; i++)
	{
		left.push_back(Max.front());
		Max.erase(Max.begin());
	}

	for (int i = middle; i < size; i++)
	{
		right.push_back(Max.front());
		Max.erase(Max.begin());
	}
	
	doRecursiveMergeSort(left);
	doRecursiveMergeSort(right);

	Max = merge(left, right);
	
}

template <typename Container>
Container PmergeMe::merge(const Container &left, const Container &right)
{
    Container result;
    typename Container::const_iterator it_left = left.begin();
    typename Container::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end())
	{
        if (*it_left <= *it_right)
		{
            result.push_back(*it_left);
            ++it_left;
        } 
		else 
		{
            result.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end())
	{
        result.push_back(*it_left);
        ++it_left;
    }
    while (it_right != right.end())
	{
        result.push_back(*it_right);
        ++it_right;
    }

    return result;
}

template <typename Container>
void PmergeMe::doFindAndMoveSmallest(Container &cont, Container &Min)
{
	typename Container::iterator it_min = Min.begin();
	typename Container::iterator it_save;
	
	int n = *it_min;
	it_save = it_min;
	++it_min;
	
	while (it_min != Min.end())
	{
		if (n > *it_min)
			n = *it_min, it_save = it_min;
		++it_min;
	}
	
	Min.erase(it_save);
	cont.insert(cont.begin(), n);
}

template <typename Container>
void PmergeMe::doFindInsertionOrder(Container &to_insert, Container &Min)
{
	int size =  Min.size();

	typename Container::iterator it_start = Min.begin();
	typename Container::iterator it_end = Min.end();

	int i = 1;
	int j = size;

	it_end--;

	while (i < j)
	{
		to_insert.insert(to_insert.begin(), *it_end);
		it_end--;
		j--;
		to_insert.insert(to_insert.begin(), *it_start);
		it_start++;
		i++;
	}
	
	if (size % 2)	
		to_insert.insert(to_insert.begin(), *it_end);
}

template <typename Container>
void PmergeMe::doInsertionAndBinarySearch(Container &to_insert, Container &Max)
{
	while (!to_insert.empty())
	{
		typename Container::iterator it_insert = to_insert.begin();
		doSearchPositionAndInsert(Max, *it_insert);
		to_insert.erase(it_insert);
	}
}

template <typename Container>
void PmergeMe::doSearchPositionAndInsert(Container &Max, int n)
{
	typename Container::iterator it_start = Max.begin();
	typename Container::iterator it_end   = Max.end();

	while (it_start != it_end)
	{
		typename Container::iterator it_middle = it_start;
		std::advance(it_middle, std::distance(it_start, it_end) / 2);
		
		if (n > *it_middle)
			it_start = ++it_middle;
		else if (n < *it_middle)
			it_end = it_middle;
	}

	Max.insert(it_start, n);
}

#endif
