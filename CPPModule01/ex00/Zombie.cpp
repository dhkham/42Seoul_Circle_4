/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:55:46 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 18:42:59 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

// constructor of the Zombie class
// ": name(_name)" is an initializer list that initializes the name member variable of the Zombie class with the value of _name passed to the constructor.
Zombie::Zombie(std::string _name) : name(_name) {}

// destructor for the Zombie class
// executed when an object goes out of scope or is explicitly deleted.
Zombie::~Zombie() {
    std::cout << name << " is destroyed!" << std::endl;
}

// announce member function for the Zombie class
// const keyword specifies that member function does not modify any of the member variables and does not call any non-const member functions.
void Zombie::announce() const {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
