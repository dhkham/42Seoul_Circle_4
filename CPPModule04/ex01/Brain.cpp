/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:35:26 by dkham             #+#    #+#             */
/*   Updated: 2023/10/13 19:35:30 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for(unsigned int i = 0; i < ideasSize; i++) {
        ideas[i] = other.ideas[i];
    }
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other) {
        for(unsigned int i = 0; i < ideasSize; i++) {
            ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

void Brain::setIdea(unsigned int index, const std::string& idea) {
    if(index < ideasSize) {
        ideas[index] = idea;
    }
}

std::string Brain::getIdea(unsigned int index) const {
    if(index < ideasSize) {
        return ideas[index];
    }
    return "";
}
