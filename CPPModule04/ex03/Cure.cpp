/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:01:54 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 17:36:36 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other) {}

Cure::~Cure() {}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
    }
    return *this;
}

AMateria* Cure::clone() const {
    return new Cure(*this); // clone returns a new instance of the class
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
