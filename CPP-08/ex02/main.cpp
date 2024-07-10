/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:13:29 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/10 14:44:26 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
void printStack(const MutantStack<T> &stack) {
    typename MutantStack<T>::const_iterator it;
    for (it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
 MutantStack<int> ms;

    ms.push(10);
    ms.push(20);
    ms.push(30);

    std::cout << "Stack contents: ";
    printStack(ms);

    std::cout << "Top element: " << ms.top() << std::endl;
    ms.pop();
    std::cout << "After pop, top element: " << ms.top() << std::endl;

    std::cout << "Stack size: " << ms.size() << std::endl;
    std::cout << "Is stack empty? " << (ms.empty() ? "Yes" : "No") << std::endl;

    std::cout << "Using iterators: ";
    MutantStack<int>::iterator it;
    for (it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Using reverse iterators: ";
    MutantStack<int>::reverse_iterator rit;
    for (rit = ms.rbegin(); rit != ms.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    return 0;
}

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }