/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:13:38 by dkham             #+#    #+#             */
/*   Updated: 2023/10/12 20:46:24 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
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
    void attack(const std::string& target);
    void guardGate();
};

#endif