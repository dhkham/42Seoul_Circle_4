/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:55:12 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 18:33:06 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name) {
	//creating an instance(=stackZombie) of the Zombie class.
	//parentheses indicates calling the constructor of the Zombie class and passing the name argument to it
    Zombie stackZombie(name);
    stackZombie.announce();
}
