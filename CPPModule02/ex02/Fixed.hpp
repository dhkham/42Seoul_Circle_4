/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:04:16 by dkham             #+#    #+#             */
/*   Updated: 2023/10/04 19:35:16 by dkham            ###   ########.fr       */
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
    
    // Overloading arithmetic operators
    Fixed operator+(const Fixed& rhs) const;
    Fixed operator-(const Fixed& rhs) const;
    Fixed operator*(const Fixed& rhs) const;
    Fixed operator/(const Fixed& rhs) const;

    // Overloading comparison operators
    bool operator>(const Fixed& rhs) const;
    bool operator<(const Fixed& rhs) const;
    bool operator>=(const Fixed& rhs) const;
    bool operator<=(const Fixed& rhs) const;
    bool operator==(const Fixed& rhs) const;
    bool operator!=(const Fixed& rhs) const;

    // Overloading increment/decrement operators
    Fixed& operator++();    // Prefix increment
    Fixed operator++(int);  // Postfix increment
    Fixed& operator--();    // Prefix decrement
    Fixed operator--(int);  // Postfix decrement

    // Static min/max functions
    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

private:
    int value;  // Holds the fixed-point value
    static const int fractionalBits = 8;  // Number of fractional bits in the fixed-point representation
};

// Non-member function to overload the << operator
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif