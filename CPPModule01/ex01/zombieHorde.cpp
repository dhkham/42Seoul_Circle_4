/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:12:05 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 19:54:43 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>  // For std::stringstream

Zombie* zombieHorde(int N, std::string name) {
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        std::stringstream zombieNameWithNumber;
        zombieNameWithNumber << name << (i + 1);  // Combining the base name with the number
        new(&horde[i]) Zombie(zombieNameWithNumber.str()); // Placement new: construct an object(=Zombie) in the already allocated memory with the constructed name
    }
    return horde;
}
