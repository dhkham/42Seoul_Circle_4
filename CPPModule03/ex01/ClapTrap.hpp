/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:02:26 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 12:53:33 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class ClapTrap {
private:
    std::string Name;
    unsigned int Hitpoints;
    unsigned int EnergyPoints;
    unsigned int AttackDamage;

public:
    // Default constructor
    ClapTrap();
    
    // Parameterized constructor
    ClapTrap(std::string name);
    
    // Copy constructor
    ClapTrap(const ClapTrap& other);
    
    // Copy assignment operator
    ClapTrap& operator=(const ClapTrap& other);
    
    // Destructor
    ~ClapTrap();

    // Public member functions
    void attack(std::string const& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
