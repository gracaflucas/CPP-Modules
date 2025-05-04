/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:42:51 by marvin            #+#    #+#             */
/*   Updated: 2025/05/04 11:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    std::cout << "=== Creating a zombie on the HEAP ===\n";
    Zombie* heapZombie = newZombie("HeapZ");
    heapZombie->announce();
    std::cout << "Deleting the heap zombie manually...\n";
    delete heapZombie;

    std::cout << "\n=== Creating a zombie on the STACK ===\n";
    randomChump("StackZ");
    std::cout << "\n=== End of main ===\n";
    
    return 0;
}