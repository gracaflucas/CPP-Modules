/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 00:58:47 by marvin            #+#    #+#             */
/*   Updated: 2025/05/12 00:58:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
    std::cout << "Creating ct1 with parameterized constructor:" << std::endl;
    ClapTrap ct1("Clappy");

    std::cout << "\nCreating ct2 with default constructor:" << std::endl;
    ClapTrap ct2;

    std::cout << "\nAssigning name to ct2:" << std::endl;
    ct2.setName("Trapster");

    std::cout << "\nCreating ct3 with copy constructor from ct1:" << std::endl;
    ClapTrap ct3(ct1);

    std::cout << "\nAssigning ct2 = ct1 using copy assignment operator:" << std::endl;
    ct2 = ct1;

    std::cout << "\n-- Initial Status --" << std::endl;
    std::cout << ct1.getName() << ": HP=" << ct1.getHitPoints()
              << ", EP=" << ct1.getEnergyPoints()
              << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << ct2.getName() << ": HP=" << ct2.getHitPoints()
              << ", EP=" << ct2.getEnergyPoints()
              << ", AD=" << ct2.getAttackDamage() << std::endl;
    std::cout << ct3.getName() << ": HP=" << ct3.getHitPoints()
              << ", EP=" << ct3.getEnergyPoints()
              << ", AD=" << ct3.getAttackDamage() << std::endl;

    std::cout << "\n-- Actions --" << std::endl;
    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());

    ct2.beRepaired(5);

    std::cout << "\n-- After Actions --" << std::endl;
    std::cout << ct1.getName() << ": HP=" << ct1.getHitPoints()
              << ", EP=" << ct1.getEnergyPoints()
              << ", AD=" << ct1.getAttackDamage() << std::endl;
    std::cout << ct2.getName() << ": HP=" << ct2.getHitPoints()
              << ", EP=" << ct2.getEnergyPoints()
              << ", AD=" << ct2.getAttackDamage() << std::endl;

    return 0;
}
