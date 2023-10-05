/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:03:16 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 13:31:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("Danny");
    ClapTrap clap2(clap1);  // Copy constructor in action
    
    clap1.attack("TARGET-1");   // hit = 10, energy = 9
    clap1.takeDamage(3);        // hit = 7, energy = 9
    clap1.beRepaired(2);        // hit = 9, energy = 8

    // Show that the objects are distinct
    clap2.takeDamage(5);        // hit = 5, energy = 10
    
    // destroy clap1
    clap1.takeDamage(9);        // hit = 0, energy = 8
    
    // deplete clap1's energy
    clap1.attack("TARGET-2");   // hit = 9, energy = 7
    clap1.attack("TARGET-3");   // hit = 9, energy = 6
    clap1.attack("TARGET-4");   // hit = 9, energy = 5
    clap1.attack("TARGET-5");   // hit = 9, energy = 4
    clap1.attack("TARGET-6");   // hit = 9, energy = 3
    clap1.attack("TARGET-7");   // hit = 9, energy = 2
    clap1.attack("TARGET-8");   // hit = 9, energy = 1
    clap1.attack("TARGET-9");   // hit = 9, energy = 0
    clap1.beRepaired(1);        // cannot repair since energy is 0
    
    return 0;
}
