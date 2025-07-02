#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
    if (!getIsSigned())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getGradeRequiredToExecute())
        throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
