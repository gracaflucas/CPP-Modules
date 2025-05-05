/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:08:48 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 16:08:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weaponType = NULL;
}

HumanB::~HumanB() {}

void    HumanB::attack() {
    if (!this->weaponType) {
        std::cout << this->name << " has no weapon :o OH NOES" << std::endl;
        return ;
    }
    std::cout << this->name << " attacked with " << this->weaponType->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weaponType) {
    this->weaponType = &weaponType;
}
