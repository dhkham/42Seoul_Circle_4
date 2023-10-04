/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:00:58 by dkham             #+#    #+#             */
/*   Updated: 2023/10/04 14:04:24 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main(void) {
    // Create a Fixed object 'a' using the default constructor
    Fixed a;

    // Create a Fixed object 'b' by converting the integer 10 to fixed-point representation
    Fixed const b(10); // const is used to ensure that the value of the object cannot be modified

    // Create a Fixed object 'c' by converting the float 42.42 to fixed-point representation
    Fixed const c(42.42f);
	
	/*
	some floating-point numbers cannot be represented with perfect accuracy,
	especially when converting them into a different format (like a fixed-point format).

	In binary representations, some decimal fractions cannot be represented with perfect accuracy.
	Just as 1/3 cannot be accurately represented in decimal (0.3333333...), certain decimal fractions have repeating or truncating binary equivalents.

	When converting 42.42f to a fixed-point number,
	some precision may be lost due to the limited number of bits allocated to represent the fractional part and the inherent inaccuracy of binary fractional representation for some decimal numbers.
	If the floating-point number cannot be represented accurately within this space, rounding errors occur, which can manifest as slightly inaccurate results when converting back to a floating-point number for display, thus you might get 42.4219 instead of 42.42.
	*/

    // Create a Fixed object 'd' by copying the value from object 'b' using the copy constructor
    Fixed const d(b);

    // Assign a new value to object 'a' using the float-to-fixed-point conversion constructor
    // and the copy assignment operator
    a = Fixed(1234.4321f);

    // Display the floating-point representations of all the Fixed objects
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    // Convert the fixed-point representations of the objects to integers and display them
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;

    // Program returns 0 and terminates
    return 0;
}
