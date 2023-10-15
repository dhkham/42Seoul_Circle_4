/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:55:49 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 18:43:32 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// default constructor
Ice::Ice() : AMateria("ice") {}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other) {}

// virtual destructor
Ice::~Ice() {}

// copy assignment operator
Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        _type = other._type;
    }
    return *this;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
