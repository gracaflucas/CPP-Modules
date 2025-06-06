/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:06:20 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 16:06:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// como humano A precisa de uma arma pra inicializar, se é passado a referencia e é preciso
// ser criado já inicializado
// humano B pega o ponteiro, pois pode ser criado antes de atribuir o valor da arma
HumanA::HumanA(std::string name, Weapon &weaponType)
        : name(name), weaponType(weaponType) {}

HumanA::~HumanA() {}

void    HumanA::attack() {
    std::cout << this->name << " attacks with their " << this->weaponType.getType() << std::endl;
}
