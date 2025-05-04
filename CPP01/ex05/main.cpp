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

#include "Harl.hpp"

int main(int argc, char **argv) {
    if (argc > 2) {
        std::cout << "Only one complain please." << std::endl;
        return 1;
    }
    else if (argc < 2) {
        std::cout << "What a great life, no complains :)" << std::endl;
        return 1;
    }
    Harl harl;
    harl.complain(argv[1]);

    return 0;
}