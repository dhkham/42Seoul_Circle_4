/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:25:50 by dkham             #+#    #+#             */
/*   Updated: 2023/10/12 20:39:19 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
public:
    // Constructors & Destructor
    FragTrap(std::string name);
    FragTrap(const FragTrap& other); // Copy constructor
    ~FragTrap();

    // Operator overloads
    FragTrap& operator=(const FragTrap& other); // Copy assignment operator
    
    // Public member function
    void highFivesGuys(void) const;
};

#endif
