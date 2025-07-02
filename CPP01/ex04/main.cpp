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
#include <fstream>

int main(int argc, char **argv) {
    if (argc != 4) {
        std::cout << "Error: try ./replace filename s1 s2" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty() || s2.empty()) {
        std::cout << "Error: s1 and s2 cannot be empty strings." << std::endl;
        return 1;
    }
    std::ifstream input(argv[1]);
    if (!input.is_open()) {
        std::cout << "Error: couldn't open file." << std::endl;
        return 1;
    }
    std::string outputFileName = std::string(argv[1]) + ".replace";
    std::ofstream output(outputFileName.c_str());
    if (!output.is_open()) {
        std::cout << "Error: couldn't create output file." << std::endl;
        return 1;
    }
    std::string line;
    while (std::getline(input, line)) {
        size_t pos = 0;
        while ((pos = line.find(s1, pos)) != std::string::npos) {
            line.erase(pos, s1.length());
            line.insert(pos, s2);
            pos += s2.length();
        }
        output << line << std::endl;
    }
    input.close();
    output.close();
    return 0;
}