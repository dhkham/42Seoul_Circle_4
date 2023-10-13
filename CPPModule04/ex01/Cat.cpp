/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:18:41 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 19:45:38 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// default constructor
Cat::Cat() {
    type = "Cat"; // set the type attribute from Animal class
    brain = new Brain(); // dynamically allocate a new Brain instance
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
    brain = new Brain(*(other.brain)); // deep copy of the Brain instance
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    delete brain; // deallocate the dynamically allocated Brain instance
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); // call the copy assignment operator of the base class
        delete brain; // delete the existing Brain instance
        brain = new Brain(*(other.brain)); // assign a new Brain instance, deep copied
    }
    return *this;
}

void Cat::makeSound() const {
    std::cout << "Meow! Meow!" << std::endl;
}
