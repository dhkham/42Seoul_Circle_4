/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:18:59 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 18:03:00 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal(); // default constructor
    WrongAnimal(const WrongAnimal& other); // copy constructor
    ~WrongAnimal(); // destructor
    WrongAnimal& operator=(const WrongAnimal& other); // copy assignment operator

    void makeSound() const;
    std::string getType() const;
};

#endif
