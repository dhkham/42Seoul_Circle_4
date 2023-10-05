/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:01:31 by dkham             #+#    #+#             */
/*   Updated: 2023/10/04 19:26:32 by dkham            ###   ########.fr       */
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

private:
    int value;  // Holds the fixed-point value
    static const int fractionalBits = 8;  // Number of fractional bits in the fixed-point representation
};

// Non-member function to overload the << operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
