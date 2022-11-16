/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaesjeon <jaesjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:33:05 by jaesjeon          #+#    #+#             */
/*   Updated: 2022/11/16 01:02:38 by jaesjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

enum contractInfoIndex {
    firstNameIdx = 0,
    lastNameIdx,
    nicknameIdx,
    phoneNumberIdx,
    darkestSecretIdx
};

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;

    public:
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickname(std::string nickname);
        void setPhoneNumber(std::string phoneNumber);
        void setDarkestSecret(std::string darkestSecret);
        void createContact(std::string contactData[5]);
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;
};
