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

Dog::Dog() : AAnimal() {
    std::cout << "Dog default constructor called." << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain;
}

Dog::Dog(std::string name) : AAnimal(name) {
    std::cout << "Dog named constructor called." << std::endl;
    this->type = "Dog";
    this->dogBrain = new Brain;
}

Dog::Dog(const Dog& copy) : AAnimal(copy) {
    std::cout << "Dog copy constructor called." << std::endl;
    this->dogBrain = new Brain(*copy.dogBrain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assign operator constructor called." << std::endl;
    if (this != &other) {
        AAnimal::operator=(other);
        delete this->dogBrain;
        this->dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called." << std::endl;
    delete dogBrain;
}

void    Dog::makeSound() const {
    std::cout << "Dog " << this->name << ": ROOF ROOF ROOF AUUUUU" << std::endl;
}

Brain&   Dog::getBrain() const {
    return *this->dogBrain;
}