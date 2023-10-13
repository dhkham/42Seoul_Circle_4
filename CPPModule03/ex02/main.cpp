/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:52 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 14:37:33 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "### Constructors:" << std::endl;
    
    FragTrap frag1("Fraggy");
    FragTrap frag2(frag1);
    FragTrap frag3("Fragger");

    std::cout << "\n### Various Actions:" << std::endl;
    
    frag1.highFivesGuys();
    frag1.attack("Enemy1");
    
    frag3.highFivesGuys();
    frag3.attack("Enemy3");
    
    // deplete frag3's hitpoints
    frag3.takeDamage(100);
    
    std::cout << "\n### Assignments:" << std::endl;
    
    frag2 = frag3; // Invokes assignment operator
    frag2.attack("Enemy2"); // cannot attack because frag3's hitpoints are 0
    
    std::cout << "\n### Destructor Calls Follow:" << std::endl;
    
    return 0; // Objects go out of scope, calling their respective destructors
}
