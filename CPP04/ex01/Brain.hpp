/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 02:04:58 by marvin            #+#    #+#             */
/*   Updated: 2025/05/26 02:04:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain& copy);
        Brain& operator=(const Brain& other);
        ~Brain();
        void setIdea(int index, const std::string& idea);
        std::string getIdea(int index) const;
};

#endif