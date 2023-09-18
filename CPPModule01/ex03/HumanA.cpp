/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:29:18 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 21:16:10 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string _name, const Weapon& _weapon) : name(_name), weapon(_weapon) {}

void HumanA::attack() const {
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}

/*
HumanA is always armed and holds a reference to Weapon,
ensuring that it always has a valid weapon.

On the other hand, HumanB may or may not have a weapon, and thus, holds a pointer to Weapon.
If the weapon is not set for HumanB, it remains a nullptr.
*/