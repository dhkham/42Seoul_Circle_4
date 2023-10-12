/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:52 by dkham             #+#    #+#             */
/*   Updated: 2023/10/12 19:22:12 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap a("Scav1");
    a.attack("Target1");
    a.takeDamage(15);
    a.beRepaired(10);
    a.guardGate();

    ScavTrap b(a);  // Testing copy constructor
    b.attack("Target2");
    
    ScavTrap c;
    c = b;  // Testing copy assignment operator
    c.attack("Target3");

    return 0;
}
