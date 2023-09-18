/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:55:28 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 18:43:39 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//dynamically allocate (on the heap) a new Zombie object and initialize it with the provided name using the Zombie constructor.
Zombie* newZombie(std::string name) {
    return new Zombie(name);
}
