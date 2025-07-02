#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();

    std::ofstream file((target + "_shrubbery").c_str());
    file << "      /\\\n     /\\*\\\n    /\\O\\*\\\n   /*/\\/\\/\\\n"
            "  /\\O\\/\\*\\/\\\n /\\*\\/\\*\\/\\/\\\n/\\O\\/\\/*/\\/O/\\\n      ||\n      ||\n      ||\n";
    file.close();
}
