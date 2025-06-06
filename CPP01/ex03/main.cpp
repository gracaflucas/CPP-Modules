/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:58:09 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 15:58:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main() {
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        std::cout << std::endl;
    }
    Weapon club = Weapon("crude spiked club");
    HumanB jim("Jim");
    jim.setWeapon(club);
    jim.attack();
    club.setType("some other type of club");
    jim.attack();
    std::cout << std::endl;

    Weapon sword("sharp sword");
    HumanA alice("Alice", sword);
    alice.attack();
    sword.setType("rusty sword");
    alice.attack();
    std::cout << std::endl;

    Weapon dagger("dagger");
    HumanB noWeapon("NoWeapon");
    noWeapon.attack();
    noWeapon.setWeapon(dagger);
    noWeapon.attack();
    dagger.setType("poisoned dagger");
    noWeapon.attack();
    return 0;
}
