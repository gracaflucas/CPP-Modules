#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        std::cout << "--- Creating Bureaucrats ---\n";
        Bureaucrat b("Bob", 50);
        Bureaucrat a("Alice", 1);
        Bureaucrat c("Charlie", 150);

        std::cout << b << std::endl;
        std::cout << a << std::endl;
        std::cout << c << std::endl;

        std::cout << "\n--- Creating Forms ---\n";
        Form f("TaxForm", 45, 25);
        Form g("SecretForm", 1, 1);

        std::cout << f << std::endl;
        std::cout << g << std::endl;

        std::cout << "\n--- Attempting to sign forms ---\n";
        b.signForm(f);      // should fail (grade 50 > 45)
        a.signForm(f);      // should succeed (grade 1 <= 45)
        a.signForm(g);      // should succeed (grade 1 <= 1)
        c.signForm(f);      // should fail (grade 150 > 45)

        std::cout << "\n--- Check form states after signing ---\n";
        std::cout << f << std::endl;
        std::cout << g << std::endl;

        std::cout << "\n--- Edge cases: invalid grades ---\n";
        try {
            Form invalidHigh("InvalidHigh", 0, 50);
        } catch (const std::exception& e) {
            std::cerr << "Exception creating InvalidHigh: " << e.what() << std::endl;
        }
        try {
            Form invalidLow("InvalidLow", 50, 151);
        } catch (const std::exception& e) {
            std::cerr << "Exception creating InvalidLow: " << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
    }
    return 0;
}
