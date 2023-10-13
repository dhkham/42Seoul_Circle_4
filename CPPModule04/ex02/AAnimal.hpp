/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:01:18 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 20:56:20 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal {
protected:
    std::string type;
    
public:
    AAnimal();
    AAnimal(const AAnimal& other);
    virtual ~AAnimal();
    AAnimal& operator=(const AAnimal& other);

    virtual void makeSound() const = 0; // Pure virtual function
    std::string getType() const;
};

#endif
