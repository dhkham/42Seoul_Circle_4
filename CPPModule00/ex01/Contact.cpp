#include "Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickname(""), phoneNumber(""), darkestSecret("") {}

void Contact::setDetails() {
    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, firstName);
        if (firstName.empty()) {
            std::cout << "First name cannot be empty. Please enter again." << std::endl;
        }
    } while (firstName.empty());

    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, lastName);
        if (lastName.empty()) {
            std::cout << "Last name cannot be empty. Please enter again." << std::endl;
        }
    } while (lastName.empty());

    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, nickname);
        if (nickname.empty()) {
            std::cout << "Nickname cannot be empty. Please enter again." << std::endl;
        }
    } while (nickname.empty());

    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, phoneNumber);
        if (phoneNumber.empty()) {
            std::cout << "Phone number cannot be empty. Please enter again." << std::endl;
        }
    } while (phoneNumber.empty());

    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, darkestSecret);
        if (darkestSecret.empty()) {
            std::cout << "Darkest secret cannot be empty. Please enter again." << std::endl;
        }
    } while (darkestSecret.empty());
}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

void Contact::displayDetails() const {
    std::cout << "First Name: " << firstName << std::endl;
    std::cout << "Last Name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}
