#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    form = someRandomIntern.makeForm("unknown form", "Target");
    if (form)
        delete form;

    return 0;
}
