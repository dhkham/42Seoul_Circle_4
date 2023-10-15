/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:55:38 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 18:46:54 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

class Ice : public AMateria {
public:
    Ice(); // default constructor
    Ice(const Ice& other); // Copy constructor
    virtual ~Ice(); // virtual destructor
    Ice& operator=(const Ice& other); // copy assignment operator
    
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
