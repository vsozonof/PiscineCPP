/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:14:40 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/17 18:17:59 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this == &rhs)
		return (*this);
	return (*this);
}

void PmergeMe::mergeSort(std::list<int> &list)
{
	// std::cout << "Before sorting: ";
	// for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	// 	std::cout << "[" << *it << "] ";
	
	clock_t start, end;
	start = clock();

	doListSort(list);

	end = clock();
	double dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(50) << "\nTime needed: " << dif << " seconds" << std::endl;

	std::cout << "After sorting: ";
	// for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	// 	std::cout << "[" << *it << "] ";
}

void PmergeMe::mergeSort(std::vector<int> &vector)
{
	// std::cout << "\n\nBefore sorting: ";
	// for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	// 	std::cout << "[" << *it << "] ";
	
	clock_t start, end;
	start = clock();

	std::sort(vector.begin(), vector.end());

	end = clock();
	double dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;

	std::cout << std::fixed << std::setprecision(50) << "\nTime needed: " << dif << " seconds" << std::endl;

	std::cout << "After sorting: ";
	// for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
	// 	std::cout << "[" << *it << "] ";
}

void PmergeMe::doVectorSort(std::vector<int> &vector)
{
	int size = vector.size();
	if (vector.size() <= 1)
		return;
		
	std::vector<int> left;
	std::vector<int> right;

	int middle = (size + 1) / 2;

	for (int i = 0; i < middle; i++)
		left.push_back(vector[i]);

	for (int i = middle; i < size; i++)
		right.push_back(vector[i]);

	doVectorSort(left);
	doVectorSort(right);

	vector = merge(left, right);
}

void PmergeMe::doListSort(std::list<int> &list)
{
	int size = list.size();
	if (list.size() <= 1)
		return;
		
	std::list<int> left;
	std::list<int> right;

	int middle = (size + 1) / 2;


	std::list<int>::iterator it = list.begin();

	for (int i = 0; i < middle; i++)
	{
		left.push_back(*it);
		it++;
	}

	for (int i = middle; i < size; i++)
	{
		right.push_back(*it);
		it++;
	}

	doListSort(left);
	doListSort(right);

	list = merge(left, right);
}

std::vector<int> PmergeMe::merge(const std::vector<int>& left, const std::vector<int>& right)
{
	std::vector<int> result;
	std::vector<int>::const_iterator it_left = left.begin();
	std::vector<int>::const_iterator it_right = right.begin();

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

std::list<int> PmergeMe::merge(const std::list<int>& left, const std::list<int>& right)
{
    std::list<int> result;
    std::list<int>::const_iterator it_left = left.begin();
    std::list<int>::const_iterator it_right = right.begin();

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