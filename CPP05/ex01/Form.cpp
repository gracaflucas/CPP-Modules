#include "Form.hpp"

Form::Form()
    : name("Untitled"), isSigned(false), gradeRequiredToSign(75), gradeRequiredToExecute(75) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name),
      isSigned(other.isSigned),
      gradeRequiredToSign(other.gradeRequiredToSign),
      gradeRequiredToExecute(other.gradeRequiredToExecute) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const {
    return name;
}

bool Form::getIsSigned() const {
    return isSigned;
}

int Form::getGradeRequiredToSign() const {
    return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const {
    return gradeRequiredToExecute;
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > gradeRequiredToSign)
        throw GradeTooLowException();
    isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form \"" << form.getName()
       << "\", signed: " << (form.getIsSigned() ? "yes" : "no")
       << ", grade required to sign: " << form.getGradeRequiredToSign()
       << ", grade required to execute: " << form.getGradeRequiredToExecute();
    return os;
}
