/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:51:49 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 15:35:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "***Test virtual destructor" << std::endl;

    // Create array of Animal objects
    const int arrSize = 6;
    const Animal* animals[arrSize];

    // Filling the array with Dogs and Cats
    for(int k = 0; k < arrSize/2; ++k) {
        animals[k] = new Dog();
    }

    for(int k = arrSize/2; k < arrSize; ++k) {
        animals[k] = new Cat();
    }
    
    // deleting the array
    for(int k = 0; k < arrSize; ++k) {
        delete animals[k];  // virtual destructor called, deleting Brain object in case of Dog and Cat
    }
    
    std::cout << std::endl << "***Test deep copy" << std::endl;
    Dog basic;
    {
        Dog tmp = basic; // Copy constructor called
    }
        
    Dog basic2;
    {
        Dog tmp;
        tmp = basic2; // Copy assignment operator called
    }

    return 0;
}
