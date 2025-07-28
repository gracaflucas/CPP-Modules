#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : _data(new T[copy._size]), _size(copy._size) {
    for (unsigned int i = 0; i < _size; i++) {
        this->_data[i] = copy._data[i];
    }
}

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        T* newData = new T[other._size];
        for (unsigned int i = 0; i < other._size; i++) {
            this->newData[i] = other._data[i];
        }
        delete[] _data;
        _data = newData; 
        _size = other._size;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size)
        throw std::out_of_range("Index is out of bounds.");
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size)
        throw std::out_of_range("Index is out of bounds.");
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}

#endif