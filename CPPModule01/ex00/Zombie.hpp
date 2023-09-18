/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:55:56 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 18:47:58 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string _name);	// constructor
    ~Zombie();					// destructor

    void announce() const;		// member function
};
// function declaration
Zombie* newZombie(std::string name);	// dynamically creates a new Zombie object on the heap and returns a pointer to it
void randomChump(std::string name);		// creates a Zombie object on the stack and makes it announce itself

#endif
