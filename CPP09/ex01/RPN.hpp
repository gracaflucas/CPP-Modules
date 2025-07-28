#ifndef RPN_HPP
# define RPN_HPP

class RPN {
    private:

    public:
        RPN();
        RPN(const RPN& copy);
        ~RPN();

        RPN& operator=(const RPN& other);
};

#endif