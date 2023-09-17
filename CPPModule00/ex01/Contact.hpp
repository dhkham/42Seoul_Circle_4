#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

public:
    Contact();							// 생성자
    void setDetails();					// 연락처 정보 입력
    std::string getFirstName() const;
    std::string getLastName() const;	
    std::string getNickname() const;
    void displayDetails() const;		// 연락처 정보 출력
};

#endif
