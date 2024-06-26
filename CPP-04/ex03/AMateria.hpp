/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:48:04 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 14:07:29 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string _type;
	
	public:
		AMateria();
		AMateria(AMateria const & src);
		virtual ~AMateria();
		AMateria & operator=(AMateria const & rhs);
		
		AMateria(std::string const & type);
		std::string const & getType() const;
		
		virtual AMateria * clone() const = 0;
		virtual void use(ICharacter & target);
};

#endif