/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 19:55:56 by dkham             #+#    #+#             */
/*   Updated: 2023/09/17 20:04:44 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
private:
    std::string name;

public:
    Zombie(std::string _name);
    ~Zombie();

    void announce() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
