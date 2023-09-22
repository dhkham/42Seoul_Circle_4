/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 16:36:24 by dkham             #+#    #+#             */
/*   Updated: 2023/09/22 11:39:38 by dkham            ###   ########.fr       */
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
        void (Harl::*func)();	// member function pointer that points to a function in the Harl class that returns void and takes no parameters
    };

    static const FuncAssociation functionAssociations[];
	/*
	static: member belongs to the class itself rather than any specific object of the class.
	const: once the array is initialized, it cannot be modified.
	FuncAssociation functionAssociations[];: This declares an array of FuncAssociation structures.
	*/
};

#endif
