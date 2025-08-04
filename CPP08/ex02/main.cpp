#include "MutantStack.hpp"
#include <list>

int main() {
    std::cout << "--- MutantStack Subject Test ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    std::cout << "Iterating MutantStack:" << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    std::cout << "\n--- std::list Test ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Top: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;

    std::cout << "Iterating std::list:" << std::endl;
    while (lit != lite) {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "\n--- Testing const_iterator ---" << std::endl;
    const MutantStack<int> const_mstack = mstack;
    MutantStack<int>::const_iterator cit = const_mstack.begin();
    MutantStack<int>::const_iterator cite = const_mstack.end();
    while (cit != cite) {
        std::cout << *cit << std::endl;
        ++cit;
    }

    std::cout << "\n--- Testing reverse_iterator ---" << std::endl;
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    while (rit != rite) {
        std::cout << *rit << std::endl;
        ++rit;
    }

    std::cout << "\n--- Testing const_reverse_iterator ---" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = const_mstack.rbegin();
    MutantStack<int>::const_reverse_iterator crite = const_mstack.rend();
    while (crit != crite) {
        std::cout << *crit << std::endl;
        ++crit;
    }

    return 0;
}
