#include <iostream>
#include "array.h"

template<typename T, unsigned int N>
array<T,N>::array()
{
    m_size = N;
    m_array = new T[m_size];
}

template <typename T, unsigned int N>
array<T,N>::~array()
{
    if(m_array != nullptr)
    {
        delete[] m_array;
    }
}

template <typename T, unsigned int N>
array<T,N>::array(const std::initializer_list<T>& oth)
{
    m_size = oth.size();
    m_array = new T[m_size];
    for(int i = 0; i < m_size; ++i)
    {
        m_array[i] = oth.begin()[i];
    }
}

template <typename T, unsigned int N>
array<T,N>& array<T,N>::operator=(const array<T,N>& oth)
{
    if(this == &oth)
    {
        return *this;
    }
    m_size = oth.m_size;
    m_array = new T[m_size];
    for(int i = 0; i < m_size; ++i)
    {
        m_array[i] = oth.m_array[i];
    }
    return *this;
}


template <typename T, unsigned int N>
const T &array<T, N>::operator[](unsigned int pos) const
{
    return m_array[pos];
}

template <typename T, unsigned int N>
T& array<T,N>::operator[](unsigned int pos)
{
    return m_array[pos];
}

template <typename T, unsigned int N>
T& array<T,N>::front() const
{
    return m_array[0];
}

template <typename T, unsigned int N>
T& array<T,N>::back() const
{

    return m_array[m_size - 1];
}

template <typename T, unsigned int N>
T& array<T,N>::at(unsigned int pos) const
{
    try
    {
        return m_array[pos];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

template <typename T, unsigned int N>
bool array<T, N>::empety() const
{
    return !m_size;
}

template <typename T, unsigned int N>
unsigned int array<T,N>::size()
{
    return m_size;
}

template <typename T, unsigned int N>
unsigned int array<T,N>::max_size()
{
    return m_size;
}

template <typename T, unsigned int N>
typename array<T, N>::iterator array<T, N>::begin()
{
    return m_array;
}

template <typename T, unsigned int N>
typename array<T, N>::iterator array<T, N>::end()
{
    return m_array + m_size;
}

template <typename T, unsigned int N>
bool array<T, N>::iterator::operator==(array<T, N>::iterator other)
{
    return m_ptr == other.m_ptr ;
}

template <typename T, unsigned int N>
bool array<T, N>::iterator::operator!=(array<T, N>::iterator other)
{
    return m_ptr != other.m_ptr;
}

template <typename T, unsigned int N>
bool array<T, N>::iterator::operator>=(array<T, N>::iterator other)
{
    return m_ptr >= other.m_ptr;
}

template <typename T, unsigned int N>
bool array<T, N>::iterator::operator<=(array<T, N>::iterator other)
{
    return m_ptr <= other.m_ptr;
}

template <typename T, unsigned int N>
bool array<T, N>::iterator::operator>(array<T, N>::iterator other)
{
    return m_ptr > other.m_ptr;
}

template <typename T, unsigned int N>
bool array<T, N>::iterator::operator<(array<T, N>::iterator other)
{
    return m_ptr < other.m_ptr;
}

template <typename T, unsigned int N>
typename array<T, N>::iterator &array<T, N>::iterator::operator++()
{
    m_ptr += 1;
    return *this;
}

template <typename T, unsigned int N>
typename array<T, N>::iterator array<T, N>::iterator::operator++(int)
{
    auto tmp = m_ptr ;
    m_ptr += 1;
    return tmp;
}

template <typename T, unsigned int N>
typename array<T, N>::iterator &array<T, N>::iterator::operator--()
{
    m_ptr -= 1;
    return *this;
}

template <typename T, unsigned int N>
typename array<T, N>::iterator array<T, N>::iterator::operator--(int)
{
    auto tmp = m_ptr;
    m_ptr -= 1;
    return tmp;
}

template <typename T, unsigned int N>
T& array<T, N>::iterator::operator*()
{
    return *m_ptr;
}

template <typename T, unsigned int N>
const T &array<T, N>::iterator::operator*()const
{
    return *m_ptr;
}