#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b("Bob", 50);
        Form f("TaxForm", 45, 25);

        b.signForm(f); // should fail

        Bureaucrat a("Alice", 30);
        a.signForm(f); // should succeed

        std::cout << f << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
