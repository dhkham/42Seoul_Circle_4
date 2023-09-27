/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 18:15:59 by dkham             #+#    #+#             */
/*   Updated: 2023/09/27 18:36:05 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
private:
    int fixedValue; // fixed-point number value
    static const int fractionalBits = 8; // number of fractional bits

public:
    // Default constructor
    Fixed();

    // Copy constructor
    Fixed(const Fixed &src);

    // Copy assignment operator
    Fixed &operator=(const Fixed &rhs);

    // Destructor
    ~Fixed();

    // Member function to get raw bits
    int getRawBits() const;

    // Member function to set raw bits
    void setRawBits(int const raw);
};

#endif

/*
"Orthodox Canonical Form" (or sometimes called the "Big Three") refers to three special member functions 
that a class should provide definitions for if it manages resources, especially dynamic memory.

These three are:

Destructor: Ensures that any resources acquired by an object are properly released when the object is destroyed.
Copy Constructor: Helps in creating a new object as a copy of an existing object.
Copy Assignment Operator: Assigns the contents of one object to another of the same type.

If a class manages resources such as dynamically allocated memory, 
and you've found the need to define any one of the above (like the destructor to release that memory), 
it's a sign that you probably need to define or at least consider the other two as well. 
Otherwise, you might run into issues such as shallow copying, which can lead to problems like double deletion.
*/