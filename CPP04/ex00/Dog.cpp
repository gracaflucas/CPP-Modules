/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:02:07 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 01:02:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() {
    std::cout << "Dog default constructor called." << std::endl;
    this->type = "Dog";
}

Dog::Dog(std::string name) : Animal(name) {
    std::cout << "Dog named constructor called." << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog copy constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assign operator constructor called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called." << std::endl;
}

void    Dog::makeSound() const {
    std::cout << "Dog " << this->name << ": ROOF ROOF ROOF AUUUUU" << std::endl;
}