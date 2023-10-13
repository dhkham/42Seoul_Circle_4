/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:13:35 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 14:23:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default_Scav") {
    Hitpoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "Default constructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) { //tells the compiler to call the ClapTrap constructor that takes a std::string as its argument before entering the ScavTrap constructor’s body
    Hitpoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;
    std::cout << "Parameterized constructor for ScavTrap called" << std::endl;
}
/*
Construction Chaining:
Base class constructor is called.
Derived class constructor is called.
-> Initializing the base part first is crucial because the derived class’s constructor might rely on the base part being already initialized.

Destruction Chaining:
Derived class destructor is called.
Base class destructor is called.
-> The base class destructor is called first because the derived class’s destructor might rely on the base part.
*/
ScavTrap::~ScavTrap() {
    std::cout << "Destructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "Copy constructor for ScavTrap called" << std::endl;
}
/*
Beyond printing the message to the standard output, nothing else is being explicitly done.
All the member-wise copying is handed off to the base class ClapTrap's copy constructor through the initializer list (: ClapTrap(other)).
*/

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "Copy assignment operator for ScavTrap called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other); // Call the base class's assignment operator
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if(EnergyPoints > 0 && Hitpoints > 0) {
        std::cout << "ScavTrap " << Name << " attacks " << target << ", causing " << AttackDamage << " points of damage!" << std::endl;
        EnergyPoints--;
    } else {
        std::cout << "ScavTrap " << Name << " cannot attack due to " << ((Hitpoints == 0) ? "being destroyed" : "insufficient energy") << "!" << std::endl;
    }
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << Name << " has entered Gatekeeper mode." << std::endl;
}
