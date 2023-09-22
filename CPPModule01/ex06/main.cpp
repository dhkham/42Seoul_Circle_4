/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:06:32 by dkham             #+#    #+#             */
/*   Updated: 2023/09/22 13:58:08 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int getLogLevelIndex(const std::string& levelStr) {
    if (levelStr == "DEBUG") return 0;
    if (levelStr == "INFO") return 1;
    if (levelStr == "WARNING") return 2;
    if (levelStr == "ERROR") return 3;
    return 4; // Invalid index
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <log level>" << std::endl;
        return 1;
    }

    std::string levelStr = argv[1];
    Harl::LogLevel level;

    switch (getLogLevelIndex(levelStr)) {
        case 0:
            level = Harl::DEBUG;
            break;
        case 1:
            level = Harl::INFO;
            break;
        case 2:
            level = Harl::WARNING;
            break;
        case 3:
            level = Harl::ERROR;
            break;
        default:
            level = Harl::INVALID;
            break;
    }

    Harl harl;
    harl.complain(level);

    return 0;
}
