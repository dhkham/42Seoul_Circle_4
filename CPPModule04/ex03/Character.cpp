/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:57:36 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 19:11:18 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(std::string const & name) : name(name) {
    for (int i = 0; i < 4; i++) {
        inventory[i] = NULL;
    }
}

Character::Character(Character const & src) : name(src.name) { 
    for (int i = 0; i < 4; i++) {
        inventory[i] = src.inventory[i] ? src.inventory[i]->clone() : NULL;
    }
}

Character::~Character() {
    for (int i = 0; i < 4; i++) {
        delete inventory[i];
    }
}

Character & Character::operator=(Character const & rhs) {
    if (this != &rhs) {
        name = rhs.name;
        for (int i = 0; i < 4; i++) {
            delete inventory[i];
            inventory[i] = rhs.inventory[i] ? rhs.inventory[i]->clone() : NULL;
        }
    }
    return *this;
}

std::string const & Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < 4; i++) {
        if (!inventory[i]) {
            inventory[i] = m->clone();
            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) { // if idx is out of range or if the slot is empty
        return;
    }
    //delete inventory[idx]; // check!!!!!!!!!!!!! take care of this in the main function
    inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= 4 || !inventory[idx]) {
        return;
    }
    inventory[idx]->use(target);
}
