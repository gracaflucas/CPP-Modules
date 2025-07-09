#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : target("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
    std::ofstream file((target + "_shrubbery").c_str());
    file << "      /\\\n     /\\*\\\n    /\\O\\*\\\n   /*/\\/\\/\\\n"
            "  /\\O\\/\\*\\/\\\n /\\*\\/\\*\\/\\/\\\n/\\O\\/\\/*/\\/O/\\\n      ||\n      ||\n      ||\n";
    file.close();
}
