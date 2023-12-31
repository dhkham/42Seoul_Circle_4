/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:30:35 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 20:02:33 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : name(_name), weapon(NULL) {}

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
HumanA is always armed, so it holds a reference to Weapon.
The lack of nullability and the guarantee that the reference is always initialized makes it a good fit.

On the other hand, HumanB may or may not have a weapon, and thus, holds a pointer to Weapon.
If the weapon is not set for HumanB, it remains a nullptr.
*/