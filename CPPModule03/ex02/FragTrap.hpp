/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:25:50 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 14:06:38 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
    // Constructors
    FragTrap();
    FragTrap(std::string name);
    
    // Destructor
    ~FragTrap();
    
    // Copy constructor
    FragTrap(const FragTrap& other);
    
    // Copy assignment operator
    FragTrap& operator=(const FragTrap& other);

    // Public member function
    void highFivesGuys(void) const;
};

#endif
