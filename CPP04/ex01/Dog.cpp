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
    type = "Dog";
    dogBrain = new Brain;
}

Dog::Dog(const Dog& copy) : Animal(copy) {
    std::cout << "Dog copy constructor called." << std::endl;
    dogBrain = new Brain(*copy.dogBrain);
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete dogBrain;
        dogBrain = new Brain(*other.dogBrain);
    }
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called." << std::endl;
    delete dogBrain;
}

void    Dog::makeSound() const {
    std::cout << "Dog: ROOF ROOF ROOF AUUUUU" << std::endl;
}

Brain&   Dog::getBrain() const {
    return *dogBrain;
}