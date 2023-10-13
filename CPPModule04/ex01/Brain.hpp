/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:35:20 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 19:57:15 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
public:
    Brain();
    Brain(const Brain& other);
    ~Brain();

    Brain& operator=(const Brain& other);

    void setIdea(unsigned int index, const std::string& idea);
    std::string getIdea(unsigned int index) const;

private:
    static const unsigned int ideasSize = 100; // static const means that the variable is shared between all instances of the class and cannot be modified
    std::string ideas[ideasSize];
};

#endif
