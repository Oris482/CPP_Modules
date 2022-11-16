/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:28:48 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 19:37:12 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

void Contact::setFirstName(std::string firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
    this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

void Contact::createContact(std::string contactData[5]) {
    this->_firstName = contactData[firstNameIdx];
    this->_lastName = contactData[lastNameIdx];
    this->_nickname = contactData[nicknameIdx];
    this->_phoneNumber = contactData[phoneNumberIdx];
    this->_darkestSecret = contactData[darkestSecretIdx];
}

std::string Contact::getFirstName(void) const {
    return (this->_firstName);
}

std::string Contact::getLastName(void) const {
    return (this->_lastName);
}

std::string Contact::getNickname(void) const {
    return (this->_nickname);
}

std::string Contact::getPhoneNumber(void) const {
    return (this->_phoneNumber);
}

std::string Contact::getDarkestSecret(void) const {
    return (this->_darkestSecret);
}
