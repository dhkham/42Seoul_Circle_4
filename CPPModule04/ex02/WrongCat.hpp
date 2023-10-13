/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:19:24 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 19:27:51 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat(); // default constructor
    WrongCat(const WrongCat& other); // copy constructor
    ~WrongCat(); // destructor
    WrongCat& operator=(const WrongCat& other); // copy assignment operator
    
    void makeSound() const;
};

#endif
