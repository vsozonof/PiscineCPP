/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:45:59 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 10:04:11 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain * _brain;

	public:
		Cat();
		Cat(std::string type);
		Cat(Cat const & src);
		~Cat();
		Cat & operator=(Cat const & src);

		virtual void makeSound() const;
};

#endif