/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 02:04:00 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 02:04:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* animals[6] = {
        new Dog(), new Cat(), new Dog(),
        new Cat(), new Dog(), new Cat()
    };
    for (int i = 0; i < 6; ++i) {
        std::cout << animals[i]->getType() << std::endl;
    }
    for (int i = 0; i < 6; ++i) {
        delete animals[i];
    }
    Cat originalCat;
    originalCat.getBrain().setIdea(0, "Chase mice");
    originalCat.getBrain().setIdea(1, "Sleep");
    Cat copyCat = originalCat;
    originalCat.getBrain().setIdea(0, "Eat fish");
    // Check ideas in copyCat remain unchanged (deep copy)
    std::cout << "Original Cat idea 0: " << originalCat.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy Cat idea 0: " << copyCat.getBrain().getIdea(0) << std::endl;

    return 0;
}