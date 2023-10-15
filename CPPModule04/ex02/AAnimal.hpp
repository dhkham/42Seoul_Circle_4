/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:18 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 15:44:57 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
    std::string type;
    
public:
    AAnimal();
    AAnimal(const AAnimal& other);
    virtual ~AAnimal();
    AAnimal& operator=(const AAnimal& other);

    virtual void makeSound() const = 0; // by adding = 0, we make this virtual function a pure virtual function
    /*
    A pure virtual function is a virtual function for which we don’t have an implementation, but only declare it.
    Containing at least one pure virtual function makes the class "abstract".
    An abstract class that cannot be instantiated on its own and is meant to be used as a base class for other classes.
    */
    std::string getType() const;
};

#endif
