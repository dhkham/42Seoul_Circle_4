/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:03:16 by dkham             #+#    #+#             */
/*   Updated: 2023/10/12 19:09:05 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Danny");
    ClapTrap clap2(clap1);  // Copy constructor in action
    
    clap1.attack("TARGET-1");   // clap1: hit = 10, energy = 9
    clap1.takeDamage(3);        // clap1: hit = 7, energy = 9
    clap1.beRepaired(2);        // clap1: hit = 9, energy = 8

    // Show that the objects are distinct
    clap2.takeDamage(5);        // clap2: hit = 5, energy = 10
    
    // destroy clap1
    clap1.takeDamage(9);        // clap1: hit = 0, energy = 8
    
    // check if clap1 can still attack or be repaired after being destroyed
    clap1.attack("TARGET-2");   // clap1: cannot attack due to being destroyed
    clap1.beRepaired(1);        // clap1: cannot repair due to being destroyed
    
    // deplete clap2's energy using for loop
    for(int i = 0; i < 10; i++) {
        clap2.attack("TARGET-3");   // clap2: hit = 5, energy = 0
    }

    // check if clap2 can still attack or be repaired after running out of energy
    clap2.attack("TARGET-4");   // clap2: cannot attack due to insufficient energy    

    return 0;
}
