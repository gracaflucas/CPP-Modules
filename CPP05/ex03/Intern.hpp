#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
    public:
        Intern();
        Intern(const Intern&);
        Intern& operator=(const Intern&);
        ~Intern();

        AForm* makeForm(const std::string& formName, const std::string& target) const;
};

#endif
