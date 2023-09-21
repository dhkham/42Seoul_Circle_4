/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:06:32 by dkham             #+#    #+#             */
/*   Updated: 2023/09/19 17:06:37 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <log level>\n";
        return 1;
    }

    std::string levelStr = argv[1];
    Harl::LogLevel level;

    if (levelStr == "DEBUG") level = Harl::DEBUG;
    else if (levelStr == "INFO") level = Harl::INFO;
    else if (levelStr == "WARNING") level = Harl::WARNING;
    else if (levelStr == "ERROR") level = Harl::ERROR;
    else level = Harl::INVALID;

    Harl harl(level);
    harl.complain(level);

    return 0;
}
