/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 10:48:30 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/30 15:35:29 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"


// ? Test main from subject

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ie");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return (0);
}

// ? Deep Copy test

// int main()
// {
// 	Character tmp1;
//     {
//         Character tmp = tmp1;
//     }
// }

// int main()
// {
// 	std::cout << "< BASIC TESTS >\n" << std::endl;
// 	std::cout << "Creating Bob" << std::endl;
// 	Character *bob = new Character("bob");

// 	std::cout << "\n\nGiving Bob some materia" << std::endl;
// 	bob->equip(new Ice());
// 	bob->equip(new Cure());
	
// 	std::cout << "\n\nGiving Bob some more materia" << std::endl;
// 	MateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	bob->equip(src->createMateria("ice"));
// 	bob->equip(src->createMateria("cure"));

// 	std::cout << "\n\nTrying to equip a new materia with full inventory" << std::endl;
// 	bob->equip(src->createMateria("ice"));

// 	std::cout << "\n\n Unequipping a materia so you can see how well it works" << std::endl;
// 	bob->unequip(1);

// 	std::cout << "\n\nTrying to unequip a previously unequipped materia" << std::endl;
// 	bob->unequip(1);
	
// 	std::cout << "\n\nUsing Bob's materia on himself, cause why not?" << std::endl;
// 	bob->use(0, *bob);
// 	bob->use(2, *bob);
// 	bob->use(3, *bob);

// 	std::cout << "\n\nTrying to use a materia that doesn't exist" << std::endl;
// 	bob->use(4, *bob);

// 	std::cout << "\n\nDESTRUCTORS" << std::endl;
// 	delete bob;
// 	delete src;

// 	std::cout << "\n\n\n\n\n< ADVANCED TESTS >\n" << std::endl;
// 	std::cout << "Creating Dwight" << std::endl;
// 	Character *dwight = new Character("dwight");
	
// 	std::cout << "\n\nGiving Dwight some materia" << std::endl;
// 	dwight->equip(new Ice());
// 	dwight->equip(new Cure());
	
// 	std::cout << "\n\nCreating a new MateriaSource" << std::endl;
// 	MateriaSource *src2 = new MateriaSource();

// 	std::cout << "\n\nLearning too many materia" << std::endl;
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());
// 	src2->learnMateria(new Ice());

// 	std::cout << "\n\nTrying to create non-learnt materia" << std::endl;
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));
// 	dwight->equip(src2->createMateria("cure"));


// 	std::cout << "\n\nTrying to mass-unequip and learning materias" << std::endl;
// 	dwight->unequip(1);
// 	dwight->unequip(2);
// 	dwight->unequip(3);
// 	dwight->unequip(4);
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());
// 	dwight->unequip(0);
// 	dwight->equip(new Ice());

	
// 	std::cout << "\n\nDESTRUCTORS" << std::endl;
// 	delete dwight;
// 	delete src2;
// 	return 0;
// }