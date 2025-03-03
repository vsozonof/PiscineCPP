/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 08:12:24 by vsozonof          #+#    #+#             */
/*   Updated: 2025/02/26 19:32:26 by vsozonof         ###   ########.fr       */
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
		void	doFindAndMoveSmallest(Container &Max, Container &Min);

		template <typename Container>
		void	doFindInsertionOrder(Container &to_insert, Container &Min);

		template <typename Container>
		void 	doInsertionAndBinarySearch(Container &to_insert, Container &Max);
		
		template <typename Container>
		void	doSearchPositionAndInsert(Container &Max, int n);
};


// ? This function will print out 3 different data :
// ? 1. A part of the set of integers, BEFORE sorting
// ? 2. A part of the set of integers, AFTER  sorting
// ? 3. The time needed to sort the integers.
template <typename Container>
void PmergeMe::FordJohnson(Container &cont)
{
	std::cout << "Before sorting: ";
	typename Container::iterator it = cont.begin();
	for (unsigned int i = 0; i <= 9 && i < cont.size(); i++)
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
	for (unsigned int i = 0; i <= 9 && i < cont.size(); i++)
	{
		std::cout << "[" << *it << "] ";
		it++;
	}
	std::cout << "[...]\n" << std::endl;
	
	// ? Debug : prints all the container's integers
	// for (typename Container::iterator full_it = cont.begin(); full_it != cont.end(); full_it++)
	// {
	// 	std::cout << "[" << *full_it << "] ";
	// 	full_it++;
	// }
}


// ? This function handles the set of integers through
// ? every steps of the Ford Johnson Algorithm
template <typename Container>
Container PmergeMe::doSort(Container &cont)
{
	int size = cont.size();
	if (size <= 1)
		return cont;
		
	Container Max;
	Container Min;
	Container toInsert;

	// ? Step 1: Pair and compare
	doPairAndCompare(cont, Max, Min, size);
	// for (typename Container::iterator full_it = Min.begin(); full_it != Min.end(); full_it++)
	// {
	// 	std::cout << "[" << *full_it << "] ";
	// 	full_it++;
	// }

	
	
	// ? Step 2: Recursive merge sort
	doRecursiveMergeSort(Max);
	
	// ? Step 3: Find and move smallest number
	doFindAndMoveSmallest(Max, Min);

	// ? Step 4: Find insertion order
	doFindInsertionOrder(toInsert, Min);
	
	// ? Step 5: Insertion and binary search
	doInsertionAndBinarySearch(toInsert, Max);

	return Max;
}


// ? Step 1: Pair and Compare
// ? This function will form multiple pairs of integers and do a comparison
// ? within each pairs :
// ? - the smallest number of each pair is added to the Min container
// ? - the greatest number of each pair is added to the Max container
// * Exemple :
// * - 10 9 8 7 6 5 -> (10 9) (8 7) (6 5)
// * Min : 9 7 5
// * Max : 10 8 6  
// ! If the initial set of integers is odd, the last integers will be moved to Min.
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


// ? Step 2: Recursive Merge Sort
// ? This function will, along with the "merge" function, perform a
// ? recursive merge sort on the Max container.
// ?
// ? The container is recursively splitted into two halves, left and right.
// ? Once there's only one integer, the function returns and will go back into the
// ? call stack, and merge everything in an ascending order.
// * Exemple :
// * Initial call : doRecursiveMergeSort([4, 3, 2, 1])
// * |
// * |-> doRecursiveMergeSort([4, 3])
// * |	|-> doRecursiveMergeSort([4]) -> 1 digit -> returns
// * |	|-> doRecursiveMergeSort([3]) -> 1 digit -> returns
// * |	|-> merge([4], [3]) -> [3, 4]
// * |
// * |
// * |-> doRecursiveMergeSort([2, 1])
// * |	|-> doRecursiveMergeSort([2]) -> 1 digit -> returns
// * |	|-> doRecursiveMergeSort([1]) -> 1 digit -> returns
// * |	|-> merge([2], [1]) -> [1, 2]
// * |
// * |
// * |-> merge([3, 4], [1, 2]) -> [1, 2, 3, 4]
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

// ? Step 2.1: merge
// ? This function will merge two sets of integers, and sort them
// ? in ascending order
// * Exemple :
// * merge([3, 4], [1, 2]) -> [1, 2, 3, 4]
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


// ? Step 3: Find and Move Smallest
// ? This function will iterate through the Min container to find its smallest integer,
// ? once found, the integer is moved at the start of Max.
// * Exemple :
// * Min : 5 18 9 0
// * Max : 20 30 40 50
// * Move 0 at the start of Max
// * New Max : 0 20 30 40 50
template <typename Container>
void PmergeMe::doFindAndMoveSmallest(Container &Max, Container &Min)
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
	Max.insert(Max.begin(), n);
}


// ? Step 4: Finding Insertion Order
// ? This function will determine the right order of insertion, and will move
// ? the integers from Min, into a new containers, in the order they need to be
// ? inserted in Max.
// ? The insertion order starts with the integer in the middle of the set,
// ? and then alternates right and left starting from the middle, till it
// ? reaches the end of the set of integers on both ends.
// * Exemple :
// * 55 12 47 69 88
// * 47 is the middle, so it's the first to insert
// * then we alternate left and right till we reach the end on both sides so :
// * Final insertion order : 47 12 69 55 88
// ! IF the set of integers is even :
// ! 55 12 87 69
// ! 87 is chosen as the middle, then we follow the logic above.
// ? They are all added into the to_insert container, for easier insertion.
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

// ? Step 5.1: Jacobsthal?
// ? This function will insert "to_insert" into Max.
// ? - The first loop; will insert integers into Max, using number of the Jacobsthal Suite
// ? as index, until the index > than the side of the container, then we send integers to
// ? a subsequent function, to insert the integer into Max.
// * Exemple:
// * Set of integers : 10 9 8 7 6
// * Jacobsthal Suite : 0 1 1 3 5 11...
// * So we first insert the index 0, so 10, remainder is 9 8 7 6
// * Then the index 1, so 8, remainder is 9 7 6
// * Lastly, the index 1 again so 7 and remainder is 9 6
// * The next number in the jacobsthal suite is 3 but we only have 2 integers left.
// * So we're done using Jacobsthal and we just sequentially move the remaining integers.
// ? - The second loop; will insert into Max sequentially, simply sending the integers
// ? to the insertion function.
template <typename Container>
void PmergeMe::doInsertionAndBinarySearch(Container &to_insert, Container &Max)
{
	int j1 = 0;
	int j2 = 1;
	long unsigned int ins = 0;
	
	while (!to_insert.empty() && ins < to_insert.size())
	{ 
		typename Container::iterator it_jacob = to_insert.begin();
		std::advance(it_jacob, ins);
		
		doSearchPositionAndInsert(Max, *it_jacob);
		to_insert.erase(it_jacob);
		
		ins = (j1 * 2) + j2;
		j1 = j2;
		j2 = ins;
	}
		
	while (!to_insert.empty())
	{
		typename Container::iterator it_insert = to_insert.begin();
		doSearchPositionAndInsert(Max, *it_insert);
		to_insert.erase(it_insert);
	}
}

// ? Step 5.2: Insertion and Binary Search
// ? This function will search in Max the position where N should be inserted.
// ? The position is obtained through binary searches.
// ? We cut Max in two halves, left and right. We compare N with the middle of Max,
// ? if N > middle integer in Max, we will continue with the right half, and the left half
// ? if N < middle integer in Max.
// ? We then apply the same process to the half where N belongs, until N's position is found.
// * Exemple:
// * Max: 1 3 5 6 7 8 9
// * N: 4
// * N < 6
// * So we deal with the left half
// * Left Max: 1 3 5 6
// * We pick 5 as middle and N < 5
// * New Left Max: 1 3 5
// * N > 3  AND N < 5 (last middle)
// * N needs to be inserted after 3
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
		{
			it_start = it_middle;
			++it_start;
		}
		else
			it_end = it_middle;
	}

	Max.insert(it_start, n);
}

#endif
