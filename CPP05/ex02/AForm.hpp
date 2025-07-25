#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string name;
        bool              isSigned;
        const int         gradeRequiredToSign;
        const int         gradeRequiredToExecute;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName() const;
        bool               getIsSigned() const;
        int                getGradeRequiredToSign() const;
        int                getGradeRequiredToExecute() const;

        void beSigned(const Bureaucrat& b);

        void execute(Bureaucrat const & executor) const;
        
        class GradeTooHighException : public std::exception {
            public:
            const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
            public:
            const char* what() const throw();
        };
        
        class NotSignedException : public std::exception {
            public:
            const char* what() const throw();
        };

        protected:
            virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif
