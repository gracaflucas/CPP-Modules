/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:31:10 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 01:31:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    std::cout << "Default wrong animal constructor called." << std::endl;
    type = "just a Wrong Animal.";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) {
    std::cout << "Wrong animal copy constructor called." << std::endl;
    type = copy.type;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "Wrong animal assignment operator called." << std::endl;
    if (this != &other) {
        type = other.type; 
    }
    return *this;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "Default wrong animal destructor called." << std::endl;
}

void    WrongAnimal::makeSound() const {
    std::cout << "Random sound from random wrong animal." << std::endl;
}

std::string WrongAnimal::getType() const {
    return this->type;
}

void        WrongAnimal::setType(const std::string& type) {
    this->type = type;
}