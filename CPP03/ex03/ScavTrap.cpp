/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 21:32:12 by marvin            #+#    #+#             */
/*   Updated: 2025/05/22 21:32:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap name constructor called." << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& copy) : ClapTrap(copy) {
    std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
    }
    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called." << std::endl;
}

void    ScavTrap::attack(const std::string& target) {
    if (getEnergyPoints() <= 0) {
        std::cout << "ScavTrap " << getName()
                  << " has no energy points left so it couldn't attack."
                  << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << getName() << " attacks " << target
              << ", causing " << getAttackDamage() << " points of damage!"
              << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
}

void    ScavTrap::guardGate() {
    std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode." << std::endl;
}