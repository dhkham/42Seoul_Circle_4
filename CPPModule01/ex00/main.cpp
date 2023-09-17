/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:54:56 by dkham             #+#    #+#             */
/*   Updated: 2023/09/17 20:04:51 by dkham            ###   ########.fr       */
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

    return 0;
}
