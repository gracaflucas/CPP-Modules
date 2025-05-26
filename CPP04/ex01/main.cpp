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

int main()
{
    const Animal* a = new Dog();
    const Animal* b = new Cat();
    const Animal* c = new Dog();
    const Animal* d = new Cat();
    const Animal* e = new Dog();
    const Animal* f = new Cat();
    std::cout << a->getType() << " " << std::endl;
    std::cout << b->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    std::cout << d->getType() << " " << std::endl;
    std::cout << e->getType() << " " << std::endl;
    std::cout << f->getType() << " " << std::endl;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;

    Cat originalCat;
    originalCat.getBrain().setIdea(0, "Chase mice");
    originalCat.getBrain().setIdea(1, "Sleep");

    // Copy the original cat
    Cat copyCat = originalCat;

    // Change the original cat's brain idea
    originalCat.getBrain().setIdea(0, "Eat fish");

    // Check ideas in copyCat remain unchanged (deep copy)
    std::cout << "Original Cat idea 0: " << originalCat.getBrain().getIdea(0) << std::endl;
    std::cout << "Copy Cat idea 0: " << copyCat.getBrain().getIdea(0) << std::endl;

    // Should output:
    // Original Cat idea 0: Eat fish
    // Copy Cat idea 0: Chase mice  <-- if deep copy worked
    
    return 0;
}