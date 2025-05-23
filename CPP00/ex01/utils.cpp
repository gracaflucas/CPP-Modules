/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufiguei <lufiguei@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:45:54 by lufiguei          #+#    #+#             */
/*   Updated: 2025/05/23 13:45:55 by lufiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool    getNonEmptyInput(const std::string prompt, std::string& input) {
    while (42) {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
            std::cout << "So you want to leave, huh? bye\n";
            exit(0);
        }
        if (input.empty()) {
            std::cout << "Input cannot be empty. Try again." << '\n';
        }
        else {
            return true;
        }
    }
}

bool    isNumeric(const std::string number) {
    for (size_t i = 0; i < number.length(); i++) {
        if (!std::isdigit(number[i]))
            return false;
    }
    return true;
}

std::string formatField(const std::string& field) {
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return std::string(10 - field.length(), ' ') + field;
}
