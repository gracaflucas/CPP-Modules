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
}

Cat::Cat(const Cat& copy) : Animal(copy) {
    std::cout << "Cat copy constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called." << std::endl;
    if (this != &other) {
        Animal::operator=(other);
    }
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called." << std::endl;
}

void    Cat::makeSound() const {
    std::cout << "Cat : Meoooooooooooooooowwwwwww" << std::endl;
}