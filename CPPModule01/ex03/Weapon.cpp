/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:28:44 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 19:24:57 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type) {}

const std::string& Weapon::getType() const {
    return type;	//	returns a const reference to type (the trailing const means that the function cannot modify the object)
}

void Weapon::setType(const std::string& _type) {
    type = _type;	//	sets type using the new one passed as parameter
}
