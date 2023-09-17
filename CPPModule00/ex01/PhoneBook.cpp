#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}	// 생성자 초기화 목록

void PhoneBook::addContact() {
    if(contactCount < 8) {
        contacts[contactCount].setDetails();	// 연락처 자료 입력
        contactCount++;
    } else {
        for(int i = 0; i < 7; i++) {			// 가장 오래된 연락처 삭제 후 새로운 연락처 추가
            contacts[i] = contacts[i + 1];
        }
        contacts[7].setDetails();
    }
}

void PhoneBook::searchContact() const {
    std::string input;
    std::cout << "Enter the index of the contact you want to view: ";
    std::getline(std::cin, input);

	if (std::cin.eof()) {	// EOF 입력 시 종료
		std::cout << "Exiting due to EOF" << std::endl;
		exit(1);
	}
    bool isNumber = true;
    for(size_t i = 0; i < input.size(); ++i) {
        if (!isdigit(input[i])) {
            isNumber = false;
            break;
        }
    }
    if (input == "EXIT") {
        return;
    } else if (isNumber) {
        std::istringstream iss(input);	// 문자열을 정수로 변환
        int index;
        iss >> index;					// 정수로 변환된 문자열을 index에 저장
        if(index < 0 || index >= contactCount) {	// index가 0보다 작거나 연락처 수보다 크거나 같으면 오류 메시지 출력
            std::cout << "Invalid index!" << std::endl;
        } else {									// 연락처 자료 출력
            contacts[index].displayDetails();
        }
    } else {										// 오류 메시지 출력
        std::cout << "Invalid input!" << std::endl;
    }
}

std::string PhoneBook::truncateString(const std::string &str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + "."; // 인덱스 0부터 시작해 9개의 문자를 반환, 마지막에 .을 붙임
    }
    return str;
}

void PhoneBook::displayContacts() const {
    std::cout << std::right << std::setw(10) << "Index" << "|";
    std::cout << std::right << std::setw(10) << "First Name" << "|";
    std::cout << std::right << std::setw(10) << "Last Name" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;

    for(int i = 0; i < contactCount; i++) {
        std::cout << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << truncateString(contacts[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << truncateString(contacts[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << truncateString(contacts[i].getNickname()) << std::endl;
    }
}
