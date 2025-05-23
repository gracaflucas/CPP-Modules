/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 00:48:14 by marvin            #+#    #+#             */
/*   Updated: 2025/05/23 00:48:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
    std::cout << "DiamondTrap constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) {
    std::cout << "DiamondTrap name constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy) {
    std::cout << "DiamondTrap copy constructor called." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap& other) {}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called." << std::endl;
}

void    DiamondTrap::whoAmI() {
    std::cout << "ClapTrap: " << ClapTrap::name << std:endl;
    std::cout << "DiamondTrap: " << this->name << std::endl;
}