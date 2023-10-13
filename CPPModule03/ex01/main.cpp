/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:52 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 11:28:04 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    ScavTrap scav1("Danny");
    scav1.attack("Target1");    // scav1: hit = 100, energy = 49
    scav1.takeDamage(15);       // scav1: hit = 85, energy = 49
    scav1.beRepaired(10);       // scav1: hit = 95, energy = 48
    scav1.guardGate();          // scav1: has entered Gatekeeper mode
    
    // Testing copy constructor
    ScavTrap scav2(scav1);  
    scav2.attack("Target2");    // scav2: hit = 100, energy = 49
    
    ScavTrap scav3;
    // Testing copy assignment operator
    scav3 = scav2;  
    // deplete scav3's energy using for loop
    for(int i = 0; i < 47; i++) {
        scav3.attack("Target3");
    }
    scav3.attack("Target4");    // scav3: cannot attack due to insufficient energy

    return 0;
}
