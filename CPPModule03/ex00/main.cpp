/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:03:16 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 12:53:54 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    ClapTrap clap1("CL4P-TP");
    ClapTrap clap2(clap1);  // Copy constructor in action
    
    clap1.attack("TARGET-1");
    clap1.takeDamage(3);
    clap1.beRepaired(2);

    // Show that the objects are distinct
    clap2.takeDamage(5);

    return 0;
}
