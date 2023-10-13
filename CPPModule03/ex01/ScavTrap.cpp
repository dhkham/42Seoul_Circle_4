/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:13:35 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 11:12:03 by dkham            ###   ########.fr       */
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

ScavTrap::~ScavTrap() {
    std::cout << "Destructor for ScavTrap called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "Copy constructor for ScavTrap called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "Copy assignment operator for ScavTrap called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
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
