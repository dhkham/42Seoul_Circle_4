/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:18:32 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 20:57:36 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
private:
    Brain* brain; // Pointer to a Brain object

public:
    Cat();
    Cat(const Cat& other);
    virtual ~Cat();
    Cat& operator=(const Cat& other);
    
    virtual void makeSound() const;
};

#endif
