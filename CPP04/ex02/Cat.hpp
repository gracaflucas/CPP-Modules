/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 00:53:02 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 00:53:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal {
    private:
        Brain* catBrain;

    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& other);
        ~Cat();
        void    makeSound() const;
        Brain&   getBrain() const;
};

#endif