/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:24:00 by dkham             #+#    #+#             */
/*   Updated: 2023/09/18 21:30:14 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Turn-in directory : ex04/
Files to turn in : Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions : std::string::replace
Create a program that takes three parameters in the following order: a filename and
two strings, s1 and s2.
It will open the file <filename> and copies its content into a new file
<filename>.replace, replacing every occurrence of s1 with s2.
Using C file manipulation functions is forbidden and will be considered cheating. All
the member functions of the class std::string are allowed, except replace. Use them
wisely!
Of course, handle unexpected inputs and errors. You have to create and turn in your
own tests to ensure your program works as expected.
*/

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string content;

    // Open file for reading
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 2;
    }

    // Read the file into a string
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    content = buffer.str();

    inFile.close();

    // Replacing every occurrence of s1 with s2 without using std::string::replace
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }

    // Writing the modified content to <filename>.replace
    std::ofstream outFile(filename + ".replace");
    if (!outFile.is_open()) {
        std::cerr << "Error creating the output file." << std::endl;
        return 3;
    }

    outFile << content;
    outFile.close();

    return 0;
}
