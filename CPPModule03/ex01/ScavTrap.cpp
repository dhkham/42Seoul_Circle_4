/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:42:09 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 14:07:39 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Default constructor
ScavTrap::ScavTrap() : ClapTrap("DefaultScav")
{
    std::cout << "ScavTrap Default constructor called" << std::endl;
    Hitpoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

// Parameterized constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Parameterized constructor called" << std::endl;
    Hitpoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "ScavTrap Copy constructor called" << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);  // Copy base part
        // ScavTrap doesn't introduce new attributes, so nothing more to copy
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}

// Overridden attack function
void ScavTrap::attack(std::string const& target) {
    if(EnergyPoints > 0) {
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    } else {
        std::cout << "ScavTrap " << Name << " has no energy to attack!" << std::endl;
    }
}

// ScavTrap's specific function
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " has entered in Gate keeper mode." << std::endl;
}
