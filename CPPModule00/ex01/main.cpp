#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;   //Phonebook 인스턴스 생성
    std::string command;   //명령어를 저장할 변수

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);
        
        if (std::cin.eof()) {
            std::cout << "Exiting program due to EOF..." << std::endl;
            break;
        }
        if (command == "ADD") {
            phonebook.addContact();
        } else if (command == "SEARCH") {
            phonebook.displayContacts();
            phonebook.searchContact();
        } else if (command == "EXIT") {
            break;
        } else {
            std::cout << "Invalid command!" << std::endl;
        }
    }
    return 0;
}
