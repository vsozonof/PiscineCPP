/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:11:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 10:03:32 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string __type;

	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(AAnimal const & src);
		virtual ~AAnimal();
		AAnimal & operator=(AAnimal const & src);

		std::string getType() const;
		virtual void makeSound() const = 0;
};

#endif