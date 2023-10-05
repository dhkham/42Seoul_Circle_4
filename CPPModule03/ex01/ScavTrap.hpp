/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:42:23 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 14:07:35 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
    // Default constructor
    ScavTrap();
    
    // Parameterized constructor
    ScavTrap(std::string name);
    
    // Copy constructor
    ScavTrap(const ScavTrap& other);
    
    // Copy assignment operator
    ScavTrap& operator=(const ScavTrap& other);
    
    // Destructor
    ~ScavTrap();

    // Overriden attack function
    void attack(std::string const& target);
    
    // ScavTrap's specific function
    void guardGate();
    
    // Getter methods
    std::string getName() const;
    unsigned int getHitpoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;

    // Setter methods
    void setName(const std::string& name);
    void setHitpoints(unsigned int hp);
    void setEnergyPoints(unsigned int ep);
    void setAttackDamage(unsigned int ad);
};
