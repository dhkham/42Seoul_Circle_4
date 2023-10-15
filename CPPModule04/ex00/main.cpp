/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:19:47 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 14:35:08 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal(); // meta is a const pointer(-> should not modify the object via this pointer) to an Animal object
    const Animal* j = new Dog();       // j is a const pointer to a Dog object
    const Animal* i = new Cat();       // i is a const pointer to a Cat object
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound! : virtual function lets the derived classes to replace the implementation provided by the base class.
    j->makeSound();
    meta->makeSound();
    
    // testing WrongAnimal and WrongCat
    std::cout << std::endl << "***Testing WrongAnimal and WrongCat" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongI = new WrongCat();
    wrongI->makeSound(); //will output the WrongAnimal sound!
    wrongMeta->makeSound();

    // Don't forget to free the allocated memory
    std::cout << std::endl << "***Freeing the allocated memory" << std::endl;
    delete meta;
    delete j;
    delete i;
    delete wrongMeta;
    delete wrongI;

    return 0;
}