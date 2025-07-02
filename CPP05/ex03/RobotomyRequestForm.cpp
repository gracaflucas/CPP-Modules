#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "BZZZZZ... drilling noises..." << std::endl;

    std::srand(std::time(0));
    if (std::rand() % 2)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}
