/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 01:05:35 by marvin            #+#    #+#             */
/*   Updated: 2025/05/12 01:05:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name(""), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
    : name(copy.name), hitPoints(copy.hitPoints), energyPoints(copy.energyPoints), attackDamage(copy.attackDamage) {
      std::cout << "Copy constructor called." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator called." << std::endl;
    if (this != &other) {
        this->name = other.getName();
        this->hitPoints = other.getHitPoints();
        this->energyPoints = other.getEnergyPoints();
        this->attackDamage = other.getAttackDamage();
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called." << std::endl;
}

void    ClapTrap::attack(const std::string& target) {
    if (this->getEnergyPoints() <= 0) {
        std::cout << this->getName() << " has no energy points left so it couldn't attack." << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->getName() << " attacks " << target
              << ", causing " << this->getAttackDamage() << " points of damage!"
              << std::endl;
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

void    ClapTrap::takeDamage(unsigned int amount) {
    if (amount > this->getHitPoints()) {
        this->setHitPoints(0);
    }
    else {
        this->setHitPoints(this->getHitPoints() - amount);
    }
    if (this->getHitPoints() == 0) {
        std::cout << "Oh no, " << this->getName() << " has no more HP!" << std::endl;
    }
    else {
        std::cout << "ClapTrap " << this->getName() << " has taken " << amount << " of damage!" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount) {
    if (this->getEnergyPoints() <= 0) {
        std::cout << this->getName() << " has no energy points left so it couldn't be repaired." << std::endl;
        return ;
    }
    this->setHitPoints(this->getHitPoints() + amount);
    this->setEnergyPoints(this->getEnergyPoints() - 1);
}

std::string     ClapTrap::getName() const {
    return this->name;
}

unsigned int    ClapTrap::getHitPoints() const {
    return this->hitPoints;
}

unsigned int    ClapTrap::getEnergyPoints() const {
    return this->energyPoints;
}

unsigned int    ClapTrap::getAttackDamage() const {
    return this->attackDamage;
}

void    ClapTrap::setName(const std::string& name) {
    this->name = name;
}

void    ClapTrap::setHitPoints(unsigned int hitPoints) {
    this->hitPoints = hitPoints;
}

void    ClapTrap::setEnergyPoints(unsigned int energyPoints) {
    this->energyPoints = energyPoints;
}

void    ClapTrap::setAttackDamage(unsigned int attackDamage) {
    this->attackDamage = attackDamage;
}