/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:30:35 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 21:16:16 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string _name) : name(_name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& _weapon) {
    weapon = &_weapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon to attack with!" << std::endl;
    }
}

/*
HumanA is always armed and holds a reference to Weapon,
ensuring that it always has a valid weapon.

On the other hand, HumanB may or may not have a weapon, and thus, holds a pointer to Weapon.
If the weapon is not set for HumanB, it remains a nullptr.
*/