/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:06:18 by dkham             #+#    #+#             */
/*   Updated: 2023/09/22 14:01:11 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl() {}

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
	switch (level) {	// FALLTRHU: if the case is true, it will execute the next case
    case DEBUG: 	// level = 0
        debug();
        /* FALLTHRU */
    case INFO:		// level = 1
        info();
        /* FALLTHRU */
    case WARNING:	// level = 2
        warning();
        /* FALLTHRU */
    case ERROR:		// level = 3
        error();
        break;
	case INVALID:	// level = 4
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}