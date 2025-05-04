/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:30:42 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 11:30:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << this->name << " was destroyed.\n";
}

void    Zombie::announce( void ) {
    std::cout << this->name << ":  BraiiiiiiinnnzzzZ...\n";
}

void    Zombie::setName(std::string name) {
    this->name = name;
}
