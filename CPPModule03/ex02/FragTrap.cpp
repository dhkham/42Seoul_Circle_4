/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:26:20 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 14:07:15 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Default constructor
FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructor called" << std::endl;
    Hitpoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

// Parameterized constructor
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap parameterized constructor called" << std::endl;
    Hitpoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
}

// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap copy assignment operator called" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

// Public member function
void FragTrap::highFivesGuys(void) const {
    std::cout << "FragTrap " << Name << " requests for a high five!" << std::endl;
}
