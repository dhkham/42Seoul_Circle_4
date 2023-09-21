/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:12:05 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 22:26:23 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>  // For std::stringstream

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        new(&horde[i]) Zombie(name); // Placement new: construct an object(=Zombie) in the already allocated memory with the provided name
    }
    return horde;
}
