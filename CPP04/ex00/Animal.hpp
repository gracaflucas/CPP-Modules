/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:42:51 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 00:42:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

    protected:
        std::string name;
        std::string type;

    public:
        Animal();
        Animal(std::string name);
        Animal(const Animal& copy);
        Animal& operator=(const Animal& other);
        virtual ~Animal();
        virtual void    makeSound() const;
        std::string getName() const;
        std::string getType() const;
};

#endif