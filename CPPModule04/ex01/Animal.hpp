/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:18 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 18:12:15 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
protected:
    std::string type;
public:
    Animal(); // Default constructor
    Animal(const Animal& other); // Copy constructor
    virtual ~Animal(); // Destructor
    Animal& operator=(const Animal& other); // Copy assignment operator
    
    virtual void makeSound() const;
    std::string getType() const;
};

#endif
