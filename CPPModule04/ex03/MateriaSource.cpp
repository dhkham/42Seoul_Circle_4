/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:03:25 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 19:06:14 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        materias[i] = 0;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other) {
    for (int i = 0; i < 4; ++i) {
        materias[i] = other.materias[i] ? other.materias[i]->clone() : 0;
    }
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; ++i) {
        delete materias[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    if (this != &other) {
        for (int i = 0; i < 4; ++i) {
            delete materias[i];
            materias[i] = other.materias[i] ? other.materias[i]->clone() : 0;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] == 0) {
            materias[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(const std::string& type) {
    for (int i = 0; i < 4; ++i) {
        if (materias[i] && materias[i]->getType() == type) {
            return materias[i]->clone();
        }
    }
    return 0;
}
