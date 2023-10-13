/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:16:39 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 20:04:25 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    type = "Dog"; // Directly set the type here in the default constructor
    brain = new Brain();
    std::cout << "Dog constructor called" << std::endl;
}


Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain); // Deep copy of brain
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    delete brain; // Ensuring no memory leak
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other) {
        Animal::operator=(other); 
        delete brain; // Freeing existing memory before deep copying the brain
        brain = new Brain(*other.brain); // Deep copy of brain
    }
    return *this;
}

void Dog::makeSound() const {
    std::cout << "Woof! Woof!" << std::endl;
}
