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
    this->name = "";
    this->type = "just an Animal.";
}

Animal::Animal(std::string name) {
    std::cout << "Named animal constructor called." << std::endl;
    this->name = name;
    this->type = "just an Animal.";
}

Animal::Animal(const Animal& copy) {
    std::cout << "Animal copy constructor called." << std::endl;
    this->name = copy.getName();
    this->type = copy.getType();
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal assign operator constructor called." << std::endl;
    if (this != &other) {
        this->name = other.getName();
        this->type = other.getType(); 
    }
    return *this;
}

Animal::~Animal() {
    std::cout << "Default animal destructor called." << std::endl;
}

void    Animal::makeSound() const {
    std::cout << "Random sound from random animal." << std::endl;
}

std::string Animal::getName() const {
    return this->name;
}

std::string Animal::getType() const {
    return this->type;
}