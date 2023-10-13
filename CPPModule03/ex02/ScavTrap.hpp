/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:26:43 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 11:26:44 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap { //Public members of ClapTrap remain public members of ScavTrap, protected members remain protected, and private members are inaccessible directly from ScavTrap
public:
    // Constructors
    ScavTrap();
    ScavTrap(std::string name);

    // Destructor
    ~ScavTrap();

    // Copy constructor
    ScavTrap(const ScavTrap& other);
    
    // Copy assignment operator
    ScavTrap& operator=(const ScavTrap& other);

    // Member functions
    void attack(const std::string& target); //overriding the attack function inherited from ClapTrap
    void guardGate();
};

#endif