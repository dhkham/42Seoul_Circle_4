/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:28:32 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 19:35:47 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
    std::string type;	// type of the weapon

public:
    Weapon(std::string _type); // constructor
    const std::string& getType() const;		//	returns a const reference to type
    void setType(const std::string& _type);	//	sets type using the new one passed as parameter
};

#endif
