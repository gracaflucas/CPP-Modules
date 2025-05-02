/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:44:49 by lufiguei          #+#    #+#             */
/*   Updated: 2025/04/30 16:45:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << " * LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j] != '\0'; j++) {
				std::cout << (char)std::toupper(argv[i][j]);
			}
			if (i < argc - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	return (0);
}