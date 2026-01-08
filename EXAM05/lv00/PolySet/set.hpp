#ifndef SET_HPP
# define SET_HPP

# include "searchable_bag.hpp"

class set {
    private:
        searchable_bag &_bag;

    public:
        set(searchable_bag &bag);

        bool has(int value) const;
        void insert(int value);
        void insert(int *arr, int size);
        void print() const;
        void clear();
        const searchable_bag &get_bag() const;
};

#endif