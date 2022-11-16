/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:33:07 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 16:16:51 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include "Contact.hpp"

class PhoneBook {
    private:
        const static int phoneBookSize = 2;
        const static std::string::size_type columnWidth = 10;
        Contact _contacts[phoneBookSize];
        std::string contactInputData[5];
        int oldestContactIndex;
        int newestContactIndex;
        int contactDataSize;

    public:
        PhoneBook(void);
        ~PhoneBook(void);
        int getPhoneBookSize() const;
        void setContactData(std::string dataType, int dataIndex, bool isPhoneNumber);
        void clearContactData();
        bool addNewContact();
        std::string compressString(std::string::size_type width, std::string str) const;
        void printContactList(void) const;
        void printSingleContactData(void) const;
};
