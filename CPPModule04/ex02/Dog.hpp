/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:16:17 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 20:57:26 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
private:
    Brain* brain; // Pointer to a Brain object

public:
    Dog();
    Dog(const Dog& other);
    virtual ~Dog();
    Dog& operator=(const Dog& other);
    
    virtual void makeSound() const;
};

#endif

