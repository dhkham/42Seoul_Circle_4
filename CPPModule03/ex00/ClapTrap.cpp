/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:02:37 by dkham             #+#    #+#             */
/*   Updated: 2023/10/12 19:06:08 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : Name("Default"), Hitpoints(10), EnergyPoints(10), AttackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
} 

// Parameterized constructor
ClapTrap::ClapTrap(std::string name) : Name(name), Hitpoints(10), EnergyPoints(10), AttackDamage(0) {
    std::cout << "Parameterized constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        Name = other.Name;
        Hitpoints = other.Hitpoints;
        EnergyPoints = other.EnergyPoints;
        AttackDamage = other.AttackDamage;
    }
    return *this;
}

// Destructor
ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {  // Modified signature
    if(EnergyPoints > 0 && Hitpoints > 0) {
        std::cout << "ClapTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    } else {
        std::cout << "ClapTrap " << Name << " cannot attack due to " << ((Hitpoints == 0) ? "being destroyed" : "insufficient energy") << "!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    if(Hitpoints > 0) {
        // Ensure the Hitpoints will not go below 0
        if(amount >= Hitpoints) { // if amount is greater than or equal to Hitpoints, set Hitpoints to 0
            Hitpoints = 0;
        } else {
            Hitpoints -= amount;  // otherwise, subtract amount from Hitpoints
        }
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage!" << std::endl;
    }
    if(Hitpoints == 0) {
        std::cout << "ClapTrap " << Name << " is destroyed!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(Hitpoints == 0) {
        std::cout << "ClapTrap " << Name << " cannot be repaired due to being destroyed!" << std::endl;
    } else if(EnergyPoints > 0) {
        Hitpoints += amount;
        std::cout << "ClapTrap " << Name << " is repaired for " << amount << " points!" << std::endl;
        EnergyPoints--;
    } else {
        std::cout << "ClapTrap " << Name << " has no energy to repair!" << std::endl;
    }
}
