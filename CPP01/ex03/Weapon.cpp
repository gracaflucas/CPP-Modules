/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:11:55 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 16:11:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType) {
    this->type = weaponType;
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() {
    return this->type;
}

void    Weapon::setType(std::string type) {
    this->type = type;
}
