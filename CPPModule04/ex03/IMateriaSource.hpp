/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:02:25 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 16:02:29 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class IMateriaSource {
public:
    virtual ~IMateriaSource() {}

    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif
