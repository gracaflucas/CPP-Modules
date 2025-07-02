#include "AForm.hpp"

AForm::AForm()
    : name("Untitled"), isSigned(false), gradeRequiredToSign(75), gradeRequiredToExecute(75) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign),
      gradeRequiredToExecute(other.gradeRequiredToExecute) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName() const {
    return name;
}

bool AForm::getIsSigned() const {
    return isSigned;
}

int AForm::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeRequiredToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form: not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form \"" << form.getName()
       << "\", signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeRequiredToSign()
       << ", grade required to execute: " << form.getGradeRequiredToExecute();
    return os;
}
