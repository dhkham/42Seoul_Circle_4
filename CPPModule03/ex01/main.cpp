/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:43:37 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 13:43:38 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    // Test ClapTrap functionality
    ClapTrap clap("CL4P-TP");
    clap.attack("a target");
    clap.takeDamage(5);
    clap.beRepaired(3);

    // Test ScavTrap functionality
    ScavTrap scav("SC4V-TP");
    scav.attack("another target");
    scav.takeDamage(10);
    scav.beRepaired(5);
    scav.guardGate();

    // Testing copy constructor and assignment operator
    ScavTrap scav2(scav);
    ScavTrap scav3;
    scav3 = scav;
    
    return 0;
}
