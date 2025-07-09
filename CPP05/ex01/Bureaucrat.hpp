#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {
    private:
        const std::string   name;
        int                 grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        class GradeTooHighException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char *what() const throw();
        };

        const std::string&  getName() const;
        int                 getGrade() const;
        void                increment();
        void                decrement();

        void signForm(Form& form);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif