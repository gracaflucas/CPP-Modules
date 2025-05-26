/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 01:31:12 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 01:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

    protected:
        std::string name;
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(std::string name);
        WrongAnimal(const WrongAnimal& copy);
        WrongAnimal& operator=(const WrongAnimal& other);
        ~WrongAnimal();
        void    makeSound() const;
        std::string getName() const;
        std::string getType() const;
};

#endif