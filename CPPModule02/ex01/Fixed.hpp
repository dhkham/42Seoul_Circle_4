/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:01:31 by dkham             #+#    #+#             */
/*   Updated: 2023/10/04 14:02:29 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
public:
    // Constructors and Destructor
    Fixed();  						// Default constructor
    Fixed(const int intVal);  		// Constructor that accepts integer (const ensures that the parameter cannot be modified)
    Fixed(const float floatVal);  	// Constructor that accepts float
    Fixed(const Fixed& src);  		// Copy constructor
    ~Fixed();  						// Destructor

    // Operator Overloads
    Fixed& operator=(const Fixed& rhs);  // Copy assignment operator

    // Getters and Setters
    int getRawBits(void) const;
    void setRawBits(int const raw);

    // Conversion methods
    float toFloat(void) const;  // Converts fixed-point to float
    int toInt(void) const;  	// Converts fixed-point to integer

    // Friend function to overload the << operator
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
	/*
	friend keyword is used to allow the function to access the private members of the class
	:specifying that the operator<< function will have access to the private and protected members of the Fixed class
	when you use the << operator with an std::ostream on the left and a Fixed object on the right, this overloaded version of the operator is invoked, executing the functionality defined in the corresponding function definition, enabling you to define custom behavior for streaming Fixed objects into an output stream.
	*/

private:
    int value;  // Holds the fixed-point value
    static const int fractionalBits = 8;  // Number of fractional bits in the fixed-point representation
};

#endif
