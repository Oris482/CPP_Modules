/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:47:13 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 17:02:33 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

#define MSG_WRONG_IDX "Wrong index input! Please check again."

PhoneBook::PhoneBook() {
    std::cout << "PhoneBook constructed" << std::endl;
    oldestContactIndex = 0;
    newestContactIndex = -1;
    contactDataSize = 0;
};

PhoneBook::~PhoneBook() {
    std::cout << "PhoneBook desturcted" << std::endl;
};

int PhoneBook::getPhoneBookSize() const {
    return (phoneBookSize);
};

void PhoneBook::setContactData(std::string dataType, int dataIndex, bool isPhoneNumber) {
    std::string inputValue;

    while (inputValue.empty()) {
        std::cout << dataType << " : ";
        std::getline(std::cin, inputValue);
        if (std::cin.eof()) {
            std::cin.clear();
            std::clearerr(stdin);
            std::cout << std::endl;
        } else if (isPhoneNumber) {
            for (std::string::size_type i = 0; i < inputValue.length(); ++i) {
                if (!std::isdigit(inputValue[i])) {
                    std::cout << "Only digit for phone number!" << std::endl;
                    inputValue.clear();
                    continue;
                }
            }
        }
    }
    contactInputData[dataIndex] = inputValue;
}

void PhoneBook::clearContactData(void) {
    contactInputData[firstNameIdx].clear();
    contactInputData[lastNameIdx].clear();
    contactInputData[nicknameIdx].clear();
    contactInputData[phoneNumberIdx].clear();
    contactInputData[darkestSecretIdx].clear();
}

bool PhoneBook::addNewContact() {
    if (contactDataSize == phoneBookSize) {
        std::string confirmDeleteOldContract;

        while (true) {
            std::cout << "PhoneBook capacity is full. This will delete oldest contact. Confirm (Y/N) : ";
            std::getline(std::cin, confirmDeleteOldContract);
            if (std::cin.eof()) {
                std::cin.clear();
                std::clearerr(stdin);
                return false;
            } else if (confirmDeleteOldContract.compare("N") == 0) {
                return false;
            } else if (confirmDeleteOldContract.compare("Y") == 0) {
                break ;
            } else {
                continue;
            }
        }
    }
    int targetContactIdx;

    newestContactIndex++;
    if (newestContactIndex == phoneBookSize) {
        targetContactIdx = oldestContactIndex;
        oldestContactIndex++;
        newestContactIndex = 0;
        if (oldestContactIndex == phoneBookSize) oldestContactIndex = 0;
    } else {
        targetContactIdx = newestContactIndex;
    }
    setContactData("First Name", firstNameIdx, false);
    setContactData("Last Name", lastNameIdx, false);
    setContactData("Nickname", nicknameIdx, false);
    setContactData("Phone Number", phoneNumberIdx, true);
    setContactData("Darkest secret", darkestSecretIdx, false);
    _contacts[targetContactIdx].createContact(contactInputData);
    clearContactData();
    if (contactDataSize < phoneBookSize) contactDataSize++;
    return true;
};

std::string PhoneBook::compressString(std::string::size_type width, std::string str) const {
    if (str.length() <= width) {
        return str;
    } else {
        return (str.substr(0, width - 1) + ".");
    }
}

void PhoneBook::printContactList(void) const {
    if (contactDataSize == 0) {
        std::cout << "There is no contact data!" << std::endl;
        return ;
    }
    std::cout.setf (std::ios::right, std::ios::adjustfield);
    std::cout.fill('-');
    std::cout << std::setw(columnWidth) << "Index" << "|" << std::setw(columnWidth) << "First Name" \
        << "|" << std::setw(columnWidth) << "Last Name" << "|" << std::setw(columnWidth) << "Nickname" << std::endl;
    std::cout.fill(' ');

    for (int i = 0; i < this->contactDataSize; ++i) {
        std::string contactData[5];
        contactData[firstNameIdx] = compressString(columnWidth, _contacts[i].getFirstName());
        contactData[lastNameIdx] = compressString(columnWidth, _contacts[i].getLastName());
        contactData[nicknameIdx] = compressString(columnWidth, _contacts[i].getNickname());
        contactData[phoneNumberIdx] = compressString(columnWidth, _contacts[i].getPhoneNumber());
        contactData[darkestSecretIdx] = compressString(columnWidth, _contacts[i].getDarkestSecret());
        std::cout << std::setw(columnWidth) << i + 1 << "|" << std::setw(columnWidth) << contactData[firstNameIdx] \
        << "|" << std::setw(columnWidth) << contactData[lastNameIdx] << "|" << std::setw(columnWidth) \
        << std::setprecision(columnWidth) << contactData[nicknameIdx] << std::endl;
    }
    std::cout << "Total " << contactDataSize << " Data\n" << std::endl;
};

void PhoneBook::printSingleContactData(void) const {
    if (contactDataSize == 0) return ;

    int idx;
    std::cout << "Select index : ";
    std::cin >> idx;
    if (std::cin.fail()) {
        std::cout << "Cancled" << std::endl;
        std::cin.clear();
        if (std::cin.eof()) std::clearerr(stdin);
        std::cin.ignore(LLONG_MAX, '\n');
        return ;
    } else if (idx <= 0 || idx > contactDataSize) {
        std::cout << MSG_WRONG_IDX << std::endl;
        std::cin.ignore();
        return ;
    }
    idx--;
    std::cout.setf (std::ios::left, std::ios::adjustfield);
    std::cout << std::setw(14) << "First Name" << " : " << _contacts[idx].getFirstName() << std::endl;
    std::cout << std::setw(14) << "Last Name" << " : " << _contacts[idx].getLastName() << std::endl;
    std::cout << std::setw(14) << "Nickname" << " : " << _contacts[idx].getNickname() << std::endl;
    std::cout << std::setw(14) << "Phone Number" << " : " << _contacts[idx].getPhoneNumber() << std::endl;
    std::cout << std::setw(14) << "Darkest Secret" << " : " << _contacts[idx].getDarkestSecret() << std::endl;
    std::cin.ignore();
};
