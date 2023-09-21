/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:36:24 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 22:39:53 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
public:
    void complain(std::string level);

private:
    void debug();
    void info();
    void warning();
    void error();

    struct FuncAssociation {	// Structure to associate a function pointer with a string
        std::string name;		// Name of the function
        void (Harl::*func)();	// Pointer to the function
    };

    static const FuncAssociation functionAssociations[];	// Array of associations
};

#endif
