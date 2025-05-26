/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:31:16 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 01:31:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat default constructor called." << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(std::string name) : WrongAnimal(name) {
    std::cout << "WrongCat named constructor called." << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
    std::cout << "WrongCat copy constructor called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
    std::cout << "WrongCat assign operator constructor called." << std::endl;
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    return *this;
}
WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called." << std::endl;
}

void    WrongCat::makeSound() const {
    std::cout << "WrongCat " << this->name << ": WRONG Meoooooooooooooooowwwwwww" << std::endl;
}