/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsozonof <vsozonof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 02:19:02 by vsozonof          #+#    #+#             */
/*   Updated: 2024/06/26 08:40:07 by vsozonof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
const WrongAnimal* meta = new WrongAnimal();
const Animal* j = new Dog();
const WrongCat* i = new WrongCat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();

delete meta;
delete j;
delete i;

return 0;
}


// int main()
// {
// 	std::cout << "-- Animal Constructors --" << std::endl;
// 	Animal a;
// 	Animal b("Norminet");
// 	Animal c(b);

// 	std::cout << "\n-- Cat Constructors --" << std::endl;
// 	Cat d;
// 	Cat e("Lilou");
// 	Cat f(e);

// 	std::cout << "\n-- Dog Constructors --" << std::endl;
// 	Dog g;
// 	Dog h("Cox");
// 	Dog i(h);
	
// 	std::cout << "\n-- getType() --" << std::endl;
// 	std::cout << "A = " << a.getType() << std::endl;
// 	std::cout << "B = " << b.getType() << std::endl;
// 	std::cout << "C(B) = " << c.getType() << std::endl;
// 	std::cout << "D = " << d.getType() << std::endl;
// 	std::cout << "E = " << e.getType() << std::endl;
// 	std::cout << "F(E) = " << f.getType() << std::endl;
// 	std::cout << "G = " << g.getType() << std::endl;
// 	std::cout << "H = " << h.getType() << std::endl;
// 	std::cout << "I(H) = " << i.getType() << std::endl;

// 	std::cout << "\n-- Equal operator --" << std::endl;
// 	a = b;
// 	d = e;
// 	g = h;
// 	std::cout << a.getType() << std::endl;
// 	std::cout << d.getType() << std::endl;
// 	std::cout << g.getType() << std::endl;

// 	std::cout << "\n-- makeSound() --" << std::endl;
// 	a.makeSound();
// 	d.makeSound();
// 	g.makeSound();

// 	std::cout << "\n-- Destructors --" << std::endl;
// }