/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:12:05 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 19:42:27 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];	// Allocate memory for N zombies: default constructor is called
    for (int i = 0; i < N; ++i) {
        new(&horde[i]) Zombie(name); // Placement new: construct an object(=Zombie) in the already allocated memory
    }
    return horde;
}
