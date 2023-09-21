/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:58:58 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 19:26:46 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA {
private:
    std::string name;
    const Weapon& weapon;  // reference to a Weapon

public:
    HumanA(std::string _name, const Weapon& _weapon);	//	HumanA takes the Weapon in its constructor
    void attack() const;
};

#endif
