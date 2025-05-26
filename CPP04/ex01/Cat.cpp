/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:54:20 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 00:54:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() {
    std::cout << "Cat default constructor called." << std::endl;
    this->setType("Cat");
    this->catBrain = new Brain;
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat copy constructor called." << std::endl;
    this->catBrain = new Brain(*copy.catBrain);
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
        delete this->catBrain;
        this->catBrain = new Brain(*other.catBrain);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
    delete catBrain;
}

void    Cat::makeSound() const {
    std::cout << "Cat: Meoooooooooooooooowwwwwww" << std::endl;
}

Brain&   Cat::getBrain() const {
    return *this->catBrain;
}