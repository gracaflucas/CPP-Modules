/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:45:17 by lufiguei          #+#    #+#             */
/*   Updated: 2025/04/30 12:45:19 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    totalContacts = 0;
    index = 0;
}

PhoneBook::~PhoneBook() {}
    
void    PhoneBook::addContact() {
    contacts[index].setContact();
    if (totalContacts < 8)
        totalContacts++;
    index = (index + 1) % 8;
}

void    PhoneBook::displayContact() const {
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << '\n';
    for (int i = 0; i < totalContacts; i++) {
        std::cout << "         " << i << "|"
        << formatField(contacts[i].getFirstName()) << "|"
        << formatField(contacts[i].getLastName()) << "|"
        << formatField(contacts[i].getNickname()) << '\n';
    }
}

void    PhoneBook::displayContactDetails(int index) const {
    if (index < 0 || index >= totalContacts) {
        std::cout << "Invalid index!\n";
        return ;
    }
    std::cout << "First Name:     " << contacts[index].getFirstName() << '\n';
    std::cout << "Last Name:      " << contacts[index].getLastName() << '\n';
    std::cout << "Nickname:       " << contacts[index].getNickname() << '\n';
    std::cout << "Phone Number:   " << contacts[index].getNumber() << '\n';
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << '\n';
}

int    PhoneBook::getTotalContacts() const {
    return this->totalContacts;
}
