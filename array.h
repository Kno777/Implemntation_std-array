#ifndef __ARRAY__H__
#define __ARRAY__H__

#include <initializer_list>

template<typename T, unsigned int N>
class array
{
public:
    class iterator
    {
    public:
        iterator() = default;
        ~iterator() = default;
        iterator(const iterator&) = default;
        iterator(iterator &&) = default;
        iterator &operator=(const iterator &) = default;
        iterator (T* p):m_ptr{p}{};
    public:
        bool operator==(iterator);
        bool operator!=(iterator);
        bool operator<(iterator);
        bool operator<=(iterator);
        bool operator>(iterator);
        bool operator>=(iterator);
        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);
        T &operator*();
        const T &operator *() const;

    private:
        T *m_ptr;
    };
public:
    array();
    ~array();
public:
    array(const std::initializer_list<T>&);
    array &operator=(const array<T,N> &);
public:
    const T& operator[](unsigned int) const;
    T& operator[](unsigned int);
public:
    array(const array&) = delete;
    array(array&&) = delete;
public:
    bool empety() const;
    unsigned int size();
    unsigned int max_size();
    T& at(unsigned int) const;
    T& front() const;
    T& back() const;
public:
    iterator begin();
    iterator end();
private:
    unsigned int m_size;
    T * m_array;
};

#include "array_logic.hpp"

#endif // __ARRAY__H__