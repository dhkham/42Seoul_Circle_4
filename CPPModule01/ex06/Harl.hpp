/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 17:06:02 by dkham             #+#    #+#             */
/*   Updated: 2023/09/20 21:27:37 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Harl {
public:
    // enum: define a set of named constants (e.g., DEBUG = 0, INFO = 1, etc.)
    enum LogLevel { DEBUG, INFO, WARNING, ERROR, INVALID };
    
    Harl(LogLevel level); // Constructor sets the log level
    void complain(LogLevel level);
    
private:
    LogLevel currentLogLevel; // Member variable to store the current log level
    void debug();
    void info();
    void warning();
    void error();
};
