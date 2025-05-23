/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:46:00 by lufiguei          #+#    #+#             */
/*   Updated: 2025/05/23 13:46:02 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string	command;
	std::string	indexStr;
	int			index;
	PhoneBook	phonebook;

	while (42) {
		std::cout << "Enter a command: (ADD) (SEARCH) (EXIT): \n";
		std::getline(std::cin, command);
		if (command == "ADD" || command == "add") {
			phonebook.addContact();
		}
		else if (command == "SEARCH" || command == "search") {
			if (phonebook.getTotalContacts() == 0) {
				std::cout << "No contacts to display.\n";
				continue ;
			}
			phonebook.displayContact();
			std::cout << "Who you want to stalk further? index: \n";
			std::getline(std::cin, indexStr);
			if (std::cin.eof()) {
				std::cout << "So you want to leave, huh? bye\n";
				return (0);
			}
			if (!isNumeric(indexStr)) {
				std::cout << "That's not a number!\n";
				continue ;
			}
			index = std::atoi(indexStr.c_str());
			phonebook.displayContactDetails(index); 
		}
		else if (command == "EXIT" || command == "exit") {
			std::cout << "exiting the program, bye :)\n";
			break ;
		}
	}
	return (0);
}
