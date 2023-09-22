/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:06:02 by dkham             #+#    #+#             */
/*   Updated: 2023/09/22 13:52:32 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl {
public:
    // enum: define a set of named constants (e.g., DEBUG = 0, INFO = 1, WARNING = 2, ERROR = 3, INVALID = 4)
    enum LogLevel { DEBUG, INFO, WARNING, ERROR, INVALID };
    
    Harl();
    void complain(LogLevel level);
    
private:
    void debug();
    void info();
    void warning();
    void error();
};

#endif