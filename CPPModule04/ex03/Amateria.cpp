/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:55:10 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 18:39:28 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Default constructor
AMateria::AMateria() : _type("default")
{
    // Constructor body can be kept empty if there's nothing else to initialize.
}

// Constructor
AMateria::AMateria(std::string const & type) : _type(type)
{
    // Constructor body can be kept empty if there's nothing else to initialize.
}

// virtual destructor
AMateria::~AMateria()
{
    // Destructor body can be kept empty if there's no dynamic memory to delete.
    // Derived classes will call this destructor automatically after their own.
}

// Copy constructor
AMateria::AMateria(AMateria const & other) : _type(other._type)
{
    // Copy constructor body can be kept empty if there's nothing else to copy.
}

// Copy assignment operator
AMateria & AMateria::operator=(AMateria const & other)
{
    // Copy assignment operator body can be kept empty if there's nothing else to assign.
    if (this != &other)
    {
        _type = other._type;
    }
    return *this;
}

std::string const & AMateria::getType() const
{
    return _type;
}

void AMateria::use(ICharacter& target)
{
    // Default behavior can be no behavior. Derived classes should give a meaningful implementation.
    // Use target to prevent compiler warnings about unused parameters in default implementation.
    (void)target;
}
