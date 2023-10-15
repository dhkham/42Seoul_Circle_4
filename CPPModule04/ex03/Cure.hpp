/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:01:45 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 18:42:28 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria {
public:
    Cure(); // default constructor
    Cure(const Cure& other); // Copy constructor
    virtual ~Cure(); // virtual destructor
    Cure& operator=(const Cure& other); // copy assignment operator

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
