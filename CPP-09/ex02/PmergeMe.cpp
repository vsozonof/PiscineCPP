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
	std::cout << "Before sorting: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << "[" << *it << "] ";
	
	time_t start,end;
	time (&start);

	if (list.size() <= 1)
		return;

	time (&end);
	double dif = difftime (end,start);
	std::cout << "\nTime needed: " << dif << std::endl;

	std::cout << "\nAfter sorting: ";
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		std::cout << "[" << *it << "] ";
}
