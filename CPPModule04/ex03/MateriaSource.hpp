/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 16:03:02 by dkham             #+#    #+#             */
/*   Updated: 2023/10/15 17:31:29 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    virtual ~MateriaSource();

    MateriaSource& operator=(const MateriaSource& other);

    virtual void learnMateria(AMateria* m);
    virtual AMateria* createMateria(const std::string& type);

private:
    AMateria* materias[4];
};

#endif
