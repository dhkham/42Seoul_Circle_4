/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:54:56 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 19:04:52 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    // Creating Zombie on the heap using newZombie function
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();

    // Deleting Zombie created on the heap
    delete heapZombie;

    // Creating Zombie on the stack using randomChump function
    randomChump("StackZombie");
	
	// stackZombie is destroyed when it goes out of scope
	// heapZombie is destroyed when we call delete on it
    return 0;
}
