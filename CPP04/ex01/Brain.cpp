/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 02:22:34 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 02:22:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called." << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "";
    }
}

Brain::Brain(const Brain& copy) {
    std::cout << "Brain copy constructor called." << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = copy.ideas[i];
    }
}

Brain& Brain::operator=(const Brain& other) {
    std::cout << "Brain assign operator constructor called." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++) {
            this->ideas[i] = other.ideas[i];
        }
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called." << std::endl;
}