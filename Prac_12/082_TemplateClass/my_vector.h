#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <algorithm>
#include <initializer_list>
#include <memory>

template<typename T>
class my_vector {
public:
    explicit my_vector(size_t N=0) noexcept
            : _size(N), _data(N ? std::make_unique<T[]>(N) : nullptr) {}

    my_vector(std::initializer_list<int> lst) noexcept
            : _size(lst.size()), _data(lst.size() ? std::make_unique<T[]>(lst.size()) : nullptr) {
        std::copy(lst.begin(), lst.end(), _data.get());
    }

    my_vector(const my_vector<T>& other) noexcept
            : _size(other._size), _data(other._size ? std::make_unique<T[]>(other._size) : nullptr) {
        std::copy(other._data.get(), other._data.get() + _size, _data.get());
    }

    T& operator[](int i) {
        return _data[i];
    }

    size_t size() const {
        return _size;
    }

private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};

#endif //MY_VECTOR_H
