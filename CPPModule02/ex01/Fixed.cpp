/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:02:12 by dkham             #+#    #+#             */
/*   Updated: 2023/10/04 18:18:50 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include "stdio.h"

// Default constructor: initializes value to 0 and outputs a message
Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Integer constructor: converts int to fixed-point and outputs a message
Fixed::Fixed(const int intVal) : value(intVal << fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Float constructor: converts float to fixed-point and outputs a message
Fixed::Fixed(const float floatVal) : value(roundf(floatVal * (1 << fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}
/*
By multiplying by 2^8, you're effectively moving the binary point 8 places to the right, allowing you to store fractional values with a precision up to 2^-8 in an integer format.
This lets you perform arithmetic more quickly and accurately than floating-point arithmetic in some contexts.
We should divide by 2^8 when converting it back to a floating-point.

roundf(floatVal * (1 << fractionalBits)) = roundf(42.42 * 2^8) = roundf(10859.52) = 10860 (round the scaled value to the nearest whole number to reduce the error introduced during the conversion from float to fixed-point)

42.42    = 101010.0110101110000101001(2)
10859.52 = 101010 01101011.100001010001111011(2) (-> 소수 부분 fractional bits 8자리 확보)
이후 반올림해 정수 형태로 저장했다가, 사용 시 다시 2^8로 나누어 사용
*/

// Copy constructor: outputs a message and utilizes copy assignment to reuse code
Fixed::Fixed(const Fixed& src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

// Copy assignment operator: checks for self-assignment, copies value, and outputs a message
Fixed& Fixed::operator=(const Fixed& rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs) {
        this->value = rhs.value;
    }
    return *this;
}

// Destructor: outputs a message when an object is destroyed
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
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
/*
Dividing the float-converted value by 2^fractionalBits effectively moves the binary point fractionalBits times to the left,
turning the fixed-point number into a floating-point number.
*/

// toInt: converts the fixed-point value to an integer
int Fixed::toInt(void) const {
    return this->value >> fractionalBits; // bit-shift operation, equivalent to dividing by 2^fractionalBits.
}

// Overloaded << operator: outputs the fixed-point value as a float (used when std::cout << a is called in main.cpp)
std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat(); // Use the toFloat() member function to convert the fixed-point value to a float. << here is the stream insertion operator.
    return os;
}
