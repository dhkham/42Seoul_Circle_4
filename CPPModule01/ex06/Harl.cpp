/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:06:18 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 18:20:36 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(LogLevel level) : currentLogLevel(level) {}

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n\n";
}

void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger!\n\n";
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n\n";
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}

void Harl::complain(LogLevel level) {
    if (level < currentLogLevel) {
        std::cerr << "[ Probably complaining about insignificant problems ]\n";
        return;  // If the provided level is below the current log level, exit early.
    }

    switch (level) {
        case DEBUG:
            debug();  // Fall-through is intentional
        case INFO:
            info();
        case WARNING:
            warning();
        case ERROR:
            error();
            break;
        default:
            std::cerr << "[ Probably complaining about insignificant problems ]\n";
            break;
    }
}