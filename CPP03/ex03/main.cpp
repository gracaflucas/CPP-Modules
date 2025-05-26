/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:15:25 by marvin            #+#    #+#             */
/*   Updated: 2025/05/23 01:15:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main() {
    std::cout << "=== Creating DiamondTrap ===\n";
    DiamondTrap dt("DiamondAce");

    std::cout << "\n=== Displaying Basic Info ===\n";
    std::cout << "DiamondTrap name: " << dt.getDiamondName() << std::endl;
    std::cout << "ClapTrap name: " << dt.getName() << std::endl;
    std::cout << "Hit Points: " << dt.getHitPoints() << std::endl;
    std::cout << "Energy Points: " << dt.getEnergyPoints() << std::endl;
    std::cout << "Attack Damage: " << dt.getAttackDamage() << std::endl;

    std::cout << "\n=== Performing Actions ===\n";
    dt.attack("EvilBot");
    dt.takeDamage(20);
    dt.beRepaired(15);

    std::cout << "\n=== Identity Check ===\n";
    dt.whoAmI();

    std::cout << "\n=== Testing Copy and Assignment ===\n";
    DiamondTrap dtCopy(dt);
    DiamondTrap dtAssigned;
    dtAssigned = dt;

    std::cout << "Copied DT name: " << dtCopy.getDiamondName() << std::endl;
    std::cout << "Assigned DT name: " << dtAssigned.getDiamondName() << std::endl;

    std::cout << "\n=== Testing Name Setters ===\n";
    dtCopy.setDiamondName("CopyCat");
    std::cout << "Updated Copied DT name: " << dtCopy.getDiamondName() << std::endl;

    std::cout << "\n=== Final whoAmI Checks ===\n";
    dtCopy.whoAmI();
    dtAssigned.whoAmI();

    std::cout << "\n=== End of main ===\n";
    return 0;
}