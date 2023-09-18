/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 19:57:44 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 20:00:30 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {
    // A string variable initialized to "HI THIS IS BRAIN".
    std::string brain = "HI THIS IS BRAIN";

    // stringPTR: A pointer to the string.
    std::string* stringPTR = &brain;

    // stringREF: A reference to the string.
    std::string& stringREF = brain;

    // Printing the memory addresses:
    std::cout << "Memory address of brain: " << &brain << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // Printing the values:
    std::cout << "Value of brain: " << brain << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}
