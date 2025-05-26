/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:42:41 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 00:42:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
    std::cout << "Default animal constructor called." << std::endl;
    type = "just an Animal.";
}

Animal::Animal(const Animal& copy) {
    std::cout << "Animal copy constructor called." << std::endl;
    type = copy.type;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assign operator constructor called." << std::endl;
    if (this != &other) {
        type = other.type; 
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Default animal destructor called." << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "Random sound from random animal." << std::endl;
}

std::string Animal::getType() const {
    return this->type;
}

void        Animal::setType(const std::string& type) {
    this->type = type;
}