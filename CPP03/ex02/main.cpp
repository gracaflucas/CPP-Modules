/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:13:06 by marvin            #+#    #+#             */
/*   Updated: 2025/05/23 01:13:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main() {
    std::cout << "Creating ft1 with parameterized constructor:\n";
    FragTrap ft1("Fraggy");

    std::cout << "\nCreating ft2 with default constructor:\n";
    FragTrap ft2;

    std::cout << "\nAssigning name to ft2:\n";
    ft2.setName("Fragster");

    std::cout << "\nCreating ft3 with copy constructor from ft1:\n";
    FragTrap ft3(ft1);

    std::cout << "\nAssigning ft2 = ft1 using copy assignment operator:\n";
    ft2 = ft1;

    std::cout << "\n-- Initial Status --\n";
    std::cout << ft1.getName() << ": HP=" << ft1.getHitPoints()
              << ", EP=" << ft1.getEnergyPoints() << ", AD=" << ft1.getAttackDamage() << "\n";
    std::cout << ft2.getName() << ": HP=" << ft2.getHitPoints()
              << ", EP=" << ft2.getEnergyPoints() << ", AD=" << ft2.getAttackDamage() << "\n";
    std::cout << ft3.getName() << ": HP=" << ft3.getHitPoints()
              << ", EP=" << ft3.getEnergyPoints() << ", AD=" << ft3.getAttackDamage() << "\n";

    std::cout << "\n-- Actions --\n";
    ft1.attack("Target");
    ft2.takeDamage(5);
    ft3.beRepaired(7);
    ft3.highFivesGuys();

    std::cout << "\n-- After Actions --\n";
    std::cout << ft1.getName() << ": HP=" << ft1.getHitPoints()
              << ", EP=" << ft1.getEnergyPoints() << ", AD=" << ft1.getAttackDamage() << "\n";
    std::cout << ft2.getName() << ": HP=" << ft2.getHitPoints()
              << ", EP=" << ft2.getEnergyPoints() << ", AD=" << ft2.getAttackDamage() << "\n";
    std::cout << ft3.getName() << ": HP=" << ft3.getHitPoints()
              << ", EP=" << ft3.getEnergyPoints() << ", AD=" << ft3.getAttackDamage() << "\n";

    return 0;
}
