/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:54:39 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 19:00:55 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"

class AMateria {    // abstract class
protected:
    std::string _type;  // Type of materia

public:
    AMateria(); // default constructor
    AMateria(std::string const & type); // Constructor
    virtual ~AMateria(); // virtual destructor
    AMateria(AMateria const & other); // Copy constructor
    AMateria & operator=(AMateria const & other); // copy assignment operator

    std::string const & getType() const;  // Returns the materia type
    virtual AMateria* clone() const = 0;  // Pure virtual function to be implemented by derived classes
    virtual void use(ICharacter& target);
};

#endif
