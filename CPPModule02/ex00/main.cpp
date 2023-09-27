/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:15:00 by dkham             #+#    #+#             */
/*   Updated: 2023/09/27 21:06:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
    Fixed a; // Default constructor called (sets value to 0)
    Fixed b( a ); // Copy constructor called with 'a' as the source object (b is now a copy of a)
    Fixed c; // Default constructor called (sets value to 0)
    c = b; // Copy assignment operator called (c now has the same value as b)

    // The getRawBits member function is called for each object and its value is printed.
    std::cout << a.getRawBits() << std::endl; // Should output 0 based on the initial setup
    std::cout << b.getRawBits() << std::endl; // Should also output 0 since 'b' was a copy of 'a'
    std::cout << c.getRawBits() << std::endl; // Should also output 0 since 'c' was assigned the value of 'b'

    return 0;
} // As main function scope ends, destructors for 'a', 'b', and 'c' are called in reverse order of their creation.
