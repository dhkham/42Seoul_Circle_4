/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:12:52 by dkham             #+#    #+#             */
/*   Updated: 2023/10/12 20:29:03 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
// Include other headers if more classes are implemented, e.g., "ScavTrap.hpp"

int main() {
    std::cout << "### Constructors:" << std::endl;
    
    FragTrap frag1("Fraggy");
    FragTrap frag2(frag1);
    FragTrap frag3("Fragger");

    std::cout << "\n### Various Actions:" << std::endl;
    
    frag1.highFivesGuys();
    frag1.attack("Enemy1");
    
    frag2.highFivesGuys();
    frag2.attack("Enemy2");
    
    frag3.highFivesGuys();
    frag3.attack("Enemy3");
    
    std::cout << "\n### Assignments:" << std::endl;
    
    frag2 = frag3; // Invokes assignment operator
    
    std::cout << "\n### Destructor Calls Follow:" << std::endl;
    
    return 0; // Objects go out of scope, calling their respective destructors
}
