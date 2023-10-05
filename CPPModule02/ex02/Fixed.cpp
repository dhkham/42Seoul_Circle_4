/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 19:07:38 by dkham             #+#    #+#             */
/*   Updated: 2023/10/05 08:59:32 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Default constructor: initializes value to 0 and outputs a message
Fixed::Fixed() : value(0) {}

// Integer constructor: converts int to fixed-point and outputs a message
Fixed::Fixed(const int intVal) : value(intVal << fractionalBits) {}

// Float constructor: converts float to fixed-point and outputs a message
Fixed::Fixed(const float floatVal) : value(roundf(floatVal * (1 << fractionalBits))) {}

// Copy constructor: outputs a message and utilizes copy assignment to reuse code
Fixed::Fixed(const Fixed& src) {
    *this = src; // Utilize the already defined copy assignment operator
}

// Copy assignment operator: checks for self-assignment, copies value, and outputs a message
Fixed& Fixed::operator=(const Fixed& rhs) {
    if (this != &rhs) {
        this->value = rhs.value;
    }
    return *this;
}

// Destructor: outputs a message when an object is destroyed
Fixed::~Fixed() {
}

// Getter for raw value: returns the fixed-point value without alteration
int Fixed::getRawBits(void) const {
    return this->value;
}

// Setter for raw value: sets the fixed-point value from the provided parameter
void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

// toFloat: converts the fixed-point value to floating-point
float Fixed::toFloat(void) const {
    return static_cast<float>(this->value) / (1 << fractionalBits);
}

// toInt: converts the fixed-point value to an integer
int Fixed::toInt(void) const {
    return this->value >> fractionalBits; // bit-shift operation, equivalent to dividing by 2^fractionalBits.
}

// Overloaded << operator: outputs the fixed-point value as a float (used when std::cout << a is called in main.cpp)
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat(); // Use the toFloat() member function to convert the fixed-point value to a float. << here is the stream insertion operator.
    return os;
}

// Arithmetic Operators

// Addition: Converts operands to float, performs addition, and converts the result back to Fixed
Fixed Fixed::operator+(const Fixed& rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

// Subtraction: Converts operands to float, performs subtraction, and converts the result back to Fixed
Fixed Fixed::operator-(const Fixed& rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

// Multiplication: Converts operands to float, performs multiplication, and converts the result back to Fixed
Fixed Fixed::operator*(const Fixed& rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

// Division: Converts operands to float, performs division, and converts the result back to Fixed
// An exception is thrown if attempting to divide by zero
Fixed Fixed::operator/(const Fixed& rhs) const {
    if(rhs.toFloat() == 0) {
        throw std::runtime_error("Division by zero");
    }
    return Fixed(this->toFloat() / rhs.toFloat());
}

// Comparison Operators: Converts operands to float and performs the respective comparison

bool Fixed::operator>(const Fixed& rhs) const { return this->toFloat() > rhs.toFloat(); }
bool Fixed::operator<(const Fixed& rhs) const { return this->toFloat() < rhs.toFloat(); }
bool Fixed::operator>=(const Fixed& rhs) const { return this->toFloat() >= rhs.toFloat(); }
bool Fixed::operator<=(const Fixed& rhs) const { return this->toFloat() <= rhs.toFloat(); }
bool Fixed::operator==(const Fixed& rhs) const { return this->toFloat() == rhs.toFloat(); }
bool Fixed::operator!=(const Fixed& rhs) const { return this->toFloat() != rhs.toFloat(); }

// Increment/Decrement Operators

// Pre-increment: Increases the value by 1 (interpreted as the smallest representable epsilon)
Fixed& Fixed::operator++() {
    this->value += 1;
    return *this;
}

// Post-increment: Creates a temporary copy, increments the original object, and returns the copy
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++(); // Utilize the already defined pre-increment operator
    return tmp;
}

// Pre-decrement: Decreases the value by 1
Fixed& Fixed::operator--() {
    this->value -= 1;
    return *this;
}

// Post-decrement: Creates a temporary copy, decrements the original object, and returns the copy
Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--(); // Utilize the already defined pre-decrement operator
    return tmp;
}

// Static Min/Max Functions

// Min for non-const objects: Returns a reference to the smaller of two Fixed objects
Fixed& Fixed::min(Fixed& a, Fixed& b) { 
    return (a < b) ? a : b;
}

// Min for const objects: Returns a const reference to the smaller of two Fixed objects
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) { 
    return (a < b) ? a : b;
}

// Max for non-const objects: Returns a reference to the larger of two Fixed objects
Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

// Max for const objects: Returns a const reference to the larger of two Fixed objects
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}
