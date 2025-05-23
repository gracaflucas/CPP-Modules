/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:46:11 by lufiguei          #+#    #+#             */
/*   Updated: 2025/05/23 13:46:12 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    this->firstName = "";
    this->lastName = "";
    this->nickname = "";
    this->number = "";
    this->darkestSecret = "";
}

Contact::~Contact() {}

void    Contact::setContact() {
    std::string input;

    getNonEmptyInput("First name: ", this->firstName);
    getNonEmptyInput("Last name: ", this->lastName);
    getNonEmptyInput("Nickname: ", this->nickname);
    while (42) {
        getNonEmptyInput("Number: ", input);
        if (isNumeric(input)) {
            this->number = input;
            break ;
        }
        std::cout << "Number field can only contain numbers." << '\n';
    }
    getNonEmptyInput("Darkest Secret: ", this->darkestSecret);
}

std::string Contact::getFirstName() const {
    return this->firstName;
}

std::string Contact::getLastName() const {
    return this->lastName;
}

std::string Contact::getNickname() const {
    return this->nickname;
}

std::string Contact::getNumber() const {
    return this->number;
}

std::string Contact::getDarkestSecret() const {
    return this->darkestSecret;
}
