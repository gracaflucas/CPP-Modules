/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:08:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 03:08:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() {
    std::cout << "Default animal constructor called." << std::endl;
    type = "just an Animal.";
}

AAnimal::AAnimal(const AAnimal& copy) {
    std::cout << "AAnimal copy constructor called." << std::endl;
    type = copy.type;
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal assignment operator called." << std::endl;
    if (this != &other) {
        type = other.type; 
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Default Aanimal destructor called." << std::endl;
}

void    AAnimal::makeSound() const {
    std::cout << "Random sound from random Aanimal." << std::endl;
}

std::string AAnimal::getType() const {
    return this->type;
}

void        AAnimal::setType(const std::string& type) {
    this->type = type;
}