/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:30:25 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 21:11:32 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weapon;  // pointer to a Weapon

public:
    HumanB(std::string _name);			// HumanB takes no Weapon in its constructor
    void setWeapon(Weapon& _weapon);	// HumanB may not always have a Weapon, whereas HumanA will always be armed
    void attack() const;
};

#endif
