/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:14:33 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 19:44:18 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {}										// default constructor

Zombie::Zombie(std::string _name) : name(_name) {}		// constructor

Zombie::~Zombie() {										// destructor
    std::cout << name << " is destroyed!" << std::endl;
}

void Zombie::announce() const {							// member function
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
