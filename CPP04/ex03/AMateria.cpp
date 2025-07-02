/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:23:19 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 03:23:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(std::string const & type) {}

AMateria::AMateria(const AMateria& copy) {}

AMateria& AMateria::operator=(const AMateria& other) {}

AMateria::~AMateria() {}

std::string const & AMateria::getType() const {
    return this->type
}

AMateria* AMateria::clone() const {
    new AMateria spell;
    return *spell;
}

void AMateria::use(ICharacter& target) {}