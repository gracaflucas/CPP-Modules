/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:02:05 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 01:02:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
    private:
        Brain *dogBrain;

    public:
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& other);
        ~Dog();
        void    makeSound() const;
        Brain&   getBrain() const;
};

#endif