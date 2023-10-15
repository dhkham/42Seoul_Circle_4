/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:18 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 14:28:24 by dkham            ###   ########.fr       */
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
    /*
    virtual function:
    - virtual keyword is used to tell the compiler to perform dynamic linkage or late binding on the function.
    
    A virtual function is a member function that you expect to be redefined in derived classes.
    When you refer to a derived class object using a pointer or a reference to the base class,
    you can call a virtual function for that object and execute the derived class's version of the function.
    It essentially allows the derived classes to replace the implementation provided by the base class.
    */
    std::string getType() const;
};

#endif
