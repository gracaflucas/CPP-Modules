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
    this->name = "";
    this->type = "just an Animal.";
}

AAnimal::AAnimal(std::string name) {
    std::cout << "Named Aanimal constructor called." << std::endl;
    this->name = name;
    this->type = "just an AAnimal.";
}

AAnimal::AAnimal(const AAnimal& copy) {
    std::cout << "AAnimal copy constructor called." << std::endl;
    this->name = copy.getName();
    this->type = copy.getType();
}

AAnimal& AAnimal::operator=(const AAnimal& other) {
    std::cout << "AAnimal assign operator constructor called." << std::endl;
    if (this != &other) {
        this->name = other.getName();
        this->type = other.getType(); 
    }
    return *this;
}

AAnimal::~AAnimal() {
    std::cout << "Default Aanimal destructor called." << std::endl;
}

void    AAnimal::makeSound() const {
    std::cout << "Random sound from random Aanimal." << std::endl;
}

std::string AAnimal::getName() const {
    return this->name;
}

std::string AAnimal::getType() const {
    return this->type;
}