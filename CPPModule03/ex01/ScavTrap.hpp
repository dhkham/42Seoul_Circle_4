/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:13:38 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 10:54:14 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
