/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:57:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 15:57:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon &weaponType;
    
    public:
        HumanA(std::string name, Weapon &weaponType);
        ~HumanA();
        void    attack();
};

#endif