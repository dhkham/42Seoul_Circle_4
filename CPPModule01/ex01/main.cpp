/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 18:56:15 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 18:56:22 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    int N = 5;  // Let's create 5 zombies for testing purposes
    Zombie* horde = zombieHorde(N, "ZombieName");

    // Announce each zombie
    for (int i = 0; i < N; ++i) {
        horde[i].announce();
    }

    // Clean up the memory to avoid memory leaks
    delete[] horde;

    return 0;
}
