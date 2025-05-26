/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 03:08:23 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 03:08:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal {
    protected:
        std::string type;

    public:
        AAnimal();
        AAnimal(const AAnimal& copy);
        AAnimal& operator=(const AAnimal& other);
        virtual ~AAnimal();
        virtual void    makeSound() const = 0;
        std::string getType() const;
        void        setType(const std::string& type);
};

#endif