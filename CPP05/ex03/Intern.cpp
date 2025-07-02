#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

static AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
    struct FormType {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    FormType forms[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPresidential }
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << forms[i].name << std::endl;
            return forms[i].create(target);
        }
    }
    std::cerr << "Intern couldn't create form because form name '" << formName << "' is unknown." << std::endl;
    return NULL;
}
