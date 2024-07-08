/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 09:14:51 by vsozonof          #+#    #+#             */
/*   Updated: 2024/07/08 10:00:53 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data = Data("42", "vsozonof");
	
	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);
	
	if (ptr == &data)
		std::cout << "ptr == &data " << ptr << " " << &data << std::endl;
	else
		std::cout << "ptr != &data" << std::endl;
	
	return (0);
}