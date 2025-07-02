#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0)); // seed rand for robotomy randomness

    Bureaucrat bob("Bob", 140);
    Bureaucrat alice("Alice", 1);

    std::cout << "=== ShrubberyCreationForm ===" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        bob.signForm(shrub);     // Should succeed (sign grade 145)
        bob.executeForm(shrub);  // Should fail (exec grade 137)
        alice.executeForm(shrub); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Shrubbery error: " << e.what() << std::endl;
    }

    std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
    try {
        RobotomyRequestForm robo("target_42");
        alice.signForm(robo);     // Should succeed (sign grade 72)
        alice.executeForm(robo);  // Should succeed (exec grade 45)
    } catch (std::exception &e) {
        std::cerr << "Robotomy error: " << e.what() << std::endl;
    }

    std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
    try {
        PresidentialPardonForm pardon("Ford Prefect");
        bob.signForm(pardon);     // Should fail (sign grade 25)
        alice.signForm(pardon);   // Should succeed
        bob.executeForm(pardon);  // Should fail (exec grade 5)
        alice.executeForm(pardon); // Should succeed
    } catch (std::exception &e) {
        std::cerr << "Pardon error: " << e.what() << std::endl;
    }

    return 0;
}
