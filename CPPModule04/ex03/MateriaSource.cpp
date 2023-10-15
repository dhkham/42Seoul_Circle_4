/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:03:25 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 20:42:44 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

// default constructor
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        materias[i] = 0;
    }
}

// copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) { 
    for (int i = 0; i < 4; ++i) {
        materias[i] = other.materias[i] ? other.materias[i]->clone() : 0; // if other.materias[i] is not null, clone it, else materias[i] = 0
    }
}

// destructor
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete materias[i];
    }
}

// copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete materias[i]; // delete the current materia
            materias[i] = other.materias[i] ? other.materias[i]->clone() : 0; // if other.materias[i] is not null, clone it, else materias[i] = 0
        }
    }
    return *this;
}

/*
learnMateria():
Copies the Materia passed as a parameter and store it in memory so it can be cloned
later. Like the Character, the MateriaSource can know at most 4 Materias. They
are not necessarily unique.
*/
void MateriaSource::learnMateria(AMateria* m) {
    if (!m) {
        std::cout << "MateriaSource: Can't learn a null materia" << std::endl;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        if (materias[i] == 0) {
            materias[i] = m;
            break;
        }
    }
}

/*
createMateria():
Returns a new Materia. The latter is a copy of the Materia previously learned by
the MateriaSource whose type equals the one passed as parameter. Returns 0 if
the type is unknown.
*/
AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();    // if the materia exists and the type is the same, clone it (returns a pointer to a new instance of the class)
        }
    }
    return 0;
}
