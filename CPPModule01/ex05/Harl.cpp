/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:36:13 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 18:48:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // Create a map instance (=functionMap) to associate strings with member function pointers
    std::map<std::string, void (Harl::*)()> functionMap; // key: string, value: pointer to member function

    // Manually insert each pair into the map
    functionMap["DEBUG"] = &Harl::debug;
    functionMap["INFO"] = &Harl::info;
    functionMap["WARNING"] = &Harl::warning;
    functionMap["ERROR"] = &Harl::error;

    if (functionMap.count(level)) { // .count() returns 1 if the key exists, 0 otherwise
        (this->*functionMap[level])(); // Call the appropriate member function
    } else {
        std::cout << "Invalid complaint level!" << std::endl;
    }
}
