/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:51:49 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 15:47:23 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << std::endl << "***Test virtual destructor" << std::endl;
    
    // Test array of AAnimal objects
    const int arrSize = 6;
    const AAnimal* animals[arrSize];

    // Filling the array with Dogs and Cats
    for(int k = 0; k < arrSize/2; ++k) {
        animals[k] = new Dog();
    }

    for(int k = arrSize/2; k < arrSize; ++k) {
        animals[k] = new Cat();
    }
    
    // deleting the array
    for(int k = 0; k < arrSize; ++k) {
        delete animals[k];
    }
    
    std::cout << std::endl << "***Test deep copy" << std::endl;
    Dog basic;
    {
        Dog tmp = basic;
    }
    
    // test if error occurs when we try to make instance of AAnimal
    //AAnimal a; // error: cannot declare variable ‘a’ to be of abstract type ‘AAnimal’

    return 0;
}
