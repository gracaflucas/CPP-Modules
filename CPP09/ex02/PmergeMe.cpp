#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& copy) { (void)copy; }
PmergeMe::~PmergeMe() {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }

bool PmergeMe::isNumber(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); i++)
        if (!isdigit(str[i])) return false;
    return true;
}

void PmergeMe::validateInput(const std::vector<std::string>& args, std::vector<int>& output) {
    for (size_t i = 0; i < args.size(); i++) {
        if (!isNumber(args[i]))
            throw std::runtime_error("Invalid input: not a number.");
        long n = std::strtol(args[i].c_str(), NULL, 10);
        if (n < 0 || n > INT_MAX)
            throw std::runtime_error("Invalid input: out of range.");
        int val = static_cast<int>(n);
        if (std::find(output.begin(), output.end(), val) != output.end())
            throw std::runtime_error("Invalid input: duplicate value.");
        output.push_back(val);
    }
}

// Jacobsthal group upper-bounds: 1, 3, 5, 11, 21, 43, …
// J(n) = J(n-1) + 2*J(n-2)
static std::vector<size_t> jacobsthalBounds(size_t n) {
    std::vector<size_t> jac;
    jac.push_back(1);
    jac.push_back(3);
    while (jac.back() < n)
        jac.push_back(jac[jac.size()-1] + 2 * jac[jac.size()-2]);
    return jac;
}

// After recursively sorting largerElems, reorder 'pairs' to match that sorted order.
// All first-elements are unique (duplicates rejected at input), so the lookup is exact.
// -1 is safe as a sentinel because all first-elements are >= 1 (larger of two distinct
// non-negative values where duplicates are forbidden).
template<typename Container>
static void reorderPairs(std::vector<std::pair<int,int> >& pairs,
                         const Container& largerElems)
{
    std::vector<std::pair<int,int> > orig = pairs;
    for (size_t i = 0; i < largerElems.size(); i++) {
        for (size_t j = 0; j < orig.size(); j++) {
            if (orig[j].first == largerElems[i]) {
                pairs[i] = orig[j];
                orig[j].first = -1;
                break;
            }
        }
    }
}

void PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;

    std::vector<std::pair<int,int> > pairs;
    bool hasStraggler = (vec.size() % 2 != 0);
    int straggler = hasStraggler ? vec.back() : 0;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) {
        int a = vec[i], b = vec[i+1];
        pairs.push_back(a > b ? std::make_pair(a,b) : std::make_pair(b,a));
    }

    // Recursively sort the larger element of each pair using Ford-Johnson itself
    std::vector<int> largerElems;
    for (size_t i = 0; i < pairs.size(); i++)
        largerElems.push_back(pairs[i].first);
    mergeInsertSortVector(largerElems);
    reorderPairs(pairs, largerElems);

    std::vector<int> mainChain;
    std::vector<int> pending;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    // pending[0] <= pairs[0].first (smallest in mainChain)
    mainChain.insert(mainChain.begin(), pending[0]);

    if (pending.size() > 1) {
        std::vector<size_t> jac = jacobsthalBounds(pending.size());
        for (size_t g = 1; g < jac.size(); g++) {
            size_t lo = jac[g-1];
            if (lo >= pending.size()) break;
            size_t hi = std::min(jac[g]-1, pending.size()-1);
            // Reverse order keeps the binary-search range bounded by pairs[k].first
            for (size_t k = hi+1; k-- > lo; ) {
                std::vector<int>::iterator upper =
                    std::lower_bound(mainChain.begin(), mainChain.end(), pairs[k].first);
                std::vector<int>::iterator pos =
                    std::lower_bound(mainChain.begin(), upper, pending[k]);
                mainChain.insert(pos, pending[k]);
            }
        }
    }

    if (hasStraggler) {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    vec = mainChain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    std::vector<std::pair<int,int> > pairs;
    bool hasStraggler = (deq.size() % 2 != 0);
    int straggler = hasStraggler ? deq.back() : 0;

    for (size_t i = 0; i + 1 < deq.size(); i += 2) {
        int a = deq[i], b = deq[i+1];
        pairs.push_back(a > b ? std::make_pair(a,b) : std::make_pair(b,a));
    }

    std::deque<int> largerElems;
    for (size_t i = 0; i < pairs.size(); i++)
        largerElems.push_back(pairs[i].first);
    mergeInsertSortDeque(largerElems);
    reorderPairs(pairs, largerElems);

    std::deque<int> mainChain;
    std::vector<int> pending;
    for (size_t i = 0; i < pairs.size(); i++) {
        mainChain.push_back(pairs[i].first);
        pending.push_back(pairs[i].second);
    }

    mainChain.insert(mainChain.begin(), pending[0]);

    if (pending.size() > 1) {
        std::vector<size_t> jac = jacobsthalBounds(pending.size());
        for (size_t g = 1; g < jac.size(); g++) {
            size_t lo = jac[g-1];
            if (lo >= pending.size()) break;
            size_t hi = std::min(jac[g]-1, pending.size()-1);
            for (size_t k = hi+1; k-- > lo; ) {
                std::deque<int>::iterator upper =
                    std::lower_bound(mainChain.begin(), mainChain.end(), pairs[k].first);
                std::deque<int>::iterator pos =
                    std::lower_bound(mainChain.begin(), upper, pending[k]);
                mainChain.insert(pos, pending[k]);
            }
        }
    }

    if (hasStraggler) {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);
        mainChain.insert(pos, straggler);
    }

    deq = mainChain;
}

void PmergeMe::printSequence(const std::string& label, const std::vector<int>& seq) {
    std::cout << label;
    for (size_t i = 0; i < seq.size(); i++) {
        std::cout << seq[i];
        if (i != seq.size()-1) std::cout << " ";
    }
    std::cout << std::endl;
}

long PmergeMe::getTime() {
    struct timeval t;
    gettimeofday(&t, NULL);
    return t.tv_sec * 1000000 + t.tv_usec;
}

void PmergeMe::run(const std::vector<std::string>& args) {
    std::vector<int> inputVec;
    validateInput(args, inputVec);
    std::vector<int> vectorData = inputVec;
    std::deque<int> dequeData(inputVec.begin(), inputVec.end());
    printSequence("Before: ", inputVec);
    long startVec = getTime();
    mergeInsertSortVector(vectorData);
    long endVec = getTime();
    long startDeq = getTime();
    mergeInsertSortDeque(dequeData);
    long endDeq = getTime();
    printSequence("After:  ", vectorData);
    std::cout << "Time to process a range of " << vectorData.size()
              << " elements with std::vector: " << (endVec - startVec) << " us" << std::endl;
    std::cout << "Time to process a range of " << dequeData.size()
              << " elements with std::deque: " << (endDeq - startDeq) << " us" << std::endl;
}
