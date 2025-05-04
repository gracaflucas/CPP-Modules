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

#include <iostream>

int main() {
    std::string test = "HI THIS IS BRAIN";
    std::string* stringPTR = &test;
    std::string& stringREF = test;

    std::cout << "Memory address of the string variable: " << &test << std::endl;
    std::cout << "Memory address held by stringPTR:      " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF:      " << &stringREF << std::endl;

    std::cout << "\nValue of the string variable:         " << test << std::endl;
    std::cout << "Value pointed to by stringPTR:        " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF:        " << stringREF << std::endl;
}