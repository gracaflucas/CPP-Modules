/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 01:09:02 by marvin            #+#    #+#             */
/*   Updated: 2025/05/23 01:09:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating st1 with parameterized constructor:" << std::endl;
    ScavTrap st1("Guardian");

    std::cout << "\nCreating st2 with default constructor:" << std::endl;
    ScavTrap st2;

    std::cout << "\nAssigning name to st2:" << std::endl;
    st2.setName("Protector");

    std::cout << "\nCreating st3 with copy constructor from st1:" << std::endl;
    ScavTrap st3(st1);

    std::cout << "\nAssigning st2 = st1 using copy assignment operator:" << std::endl;
    st2 = st1;

    std::cout << "\n-- Initial Status --" << std::endl;
    std::cout << st1.getName() << ": HP=" << st1.getHitPoints()
              << ", EP=" << st1.getEnergyPoints()
              << ", AD=" << st1.getAttackDamage() << std::endl;

    std::cout << st2.getName() << ": HP=" << st2.getHitPoints()
              << ", EP=" << st2.getEnergyPoints()
              << ", AD=" << st2.getAttackDamage() << std::endl;

    std::cout << st3.getName() << ": HP=" << st3.getHitPoints()
              << ", EP=" << st3.getEnergyPoints()
              << ", AD=" << st3.getAttackDamage() << std::endl;

    std::cout << "\n-- Actions --" << std::endl;
    st1.attack("Intruder");
    st2.takeDamage(30);
    st3.beRepaired(20);
    st3.guardGate();

    std::cout << "\n-- After Actions --" << std::endl;
    std::cout << st1.getName() << ": HP=" << st1.getHitPoints()
              << ", EP=" << st1.getEnergyPoints()
              << ", AD=" << st1.getAttackDamage() << std::endl;

    std::cout << st2.getName() << ": HP=" << st2.getHitPoints()
              << ", EP=" << st2.getEnergyPoints()
              << ", AD=" << st2.getAttackDamage() << std::endl;

    std::cout << st3.getName() << ": HP=" << st3.getHitPoints()
              << ", EP=" << st3.getEnergyPoints()
              << ", AD=" << st3.getAttackDamage() << std::endl;

    return 0;
}
