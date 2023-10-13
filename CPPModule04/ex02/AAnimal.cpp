/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:16:30 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 20:56:53 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

// default constructor
AAnimal::AAnimal() : type("AAnimal") { 
    std::cout << "AAnimal constructor called" << std::endl;
}

// copy constructor
AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
    std::cout << "AAnimal copy constructor called" << std::endl;
}

// destructor
AAnimal::~AAnimal() {
    std::cout << "AAnimal destructor called" << std::endl;
}

// copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal copy assignment operator called" << std::endl;
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const {
    return type;
}
