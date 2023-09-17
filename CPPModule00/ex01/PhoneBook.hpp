#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

class PhoneBook {
private:
    Contact contacts[8]; // 연락처 배열: 최대 8개 (Contact 클래스 인스턴스 배열)
    int contactCount;	// 연락처 개수
    static std::string truncateString(const std::string &str); // 문자열 자르기 (최대 10자)

public:
    PhoneBook();					// 생성자
    void addContact();				// 연락처 추가
    void searchContact() const;		// 연락처 검색
    void displayContacts() const;	// 연락처 목록 출력
};

#endif
