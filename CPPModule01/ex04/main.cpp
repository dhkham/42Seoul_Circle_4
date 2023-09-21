/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkham <dkham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:24:00 by dkham             #+#    #+#             */
/*   Updated: 2023/09/21 18:48:41 by dkham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cout << "Error input: type in " << argv[0] << " <filename> <string1> <string2>" << std::endl;
        return 1;
    }

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string content;

    // Open file for reading
    std::ifstream inFile(filename); // std::ifstream is a class designed to handle file input operations (inFile is the instance)
    if (!inFile.is_open()) { //is_open() method of the ifstream object checks if the file was successfully opened
        std::cout << "Error opening file: " << filename << std::endl;
        return 1;
    }

    // Read the file into a string
    std::stringstream buffer; // std::stringstream is a stream class to operate on strings (buffer is the instance)
    buffer << inFile.rdbuf(); // returns a pointer to the internal stream buffer object associated with the inFile object (the file stream).
    content = buffer.str(); // returns a string object with a copy of the current contents of the stream

    inFile.close(); // close the file

    // Check if s1 exists in the content
    if (content.find(s1) == std::string::npos) { // if not found, returns std::string::npos
        std::cout << "Error: The string '" << s1 << "' was not found in the file: " << filename << std::endl;
        return 1;
    }
    
    // Replacing every occurrence of s1 with s2 without using std::string::replace
    size_t pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos) { // content.find(s1, pos) starts finding from pos and returns the position of the first character of the first match (if not found, returns std::string::npos)
        content.erase(pos, s1.length()); // erase the s1
        content.insert(pos, s2);    // insert the s2
        pos += s2.length(); // update the pos
    }

    // Writing the modified content to <filename>.replace
    std::ofstream outFile(filename + ".replace");   // std::ofstream is a class designed to handle file output operations (outFile is the instance)
    if (!outFile.is_open()) {
        std::cout << "Error creating the output file." << std::endl;
        return 1;
    }

    outFile << content; // write the content to the file
    outFile.close(); // close the file

    return 0;
}
