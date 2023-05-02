#pragma once
#include <iostream>
#include <cstring>

template <typename T>
class CustomVector
{
private:
    T *array;
    int size;
    int capacity;

public:
    CustomVector()
    {
        size = 0;
        capacity = 10;
        array = new T[capacity];
    }

    CustomVector(int n)
    {
        size = 0;
        capacity = n;
        array = new T[capacity];
    }

    CustomVector(int size_, const T &initialValue) : array(new T[size_]), size(size_)
    {
        for (int i = 0; i < size; ++i)
        {
            array[i] = initialValue;
        }
    }


    CustomVector(const CustomVector &other)
        : size(other.size), array(new T[size])
    {
        for (int i = 0; i < size; ++i)
        {
            array[i] = other.array[i];
        }
    }

    // Copy assignment operator
    CustomVector &operator=(const CustomVector &other)
    {
        if (this != &other)
        {
            delete[] array;
            size = other.size;
            array = new T[size];
            for (int i = 0; i < size; ++i)
            {
                array[i] = other.array[i];
            }
        }
        return *this;
    }


    // ~CustomVector()
    // {
    //     delete[] array;
    // }

    void push_back(T value)
    {
        if (size == capacity)
        {
            capacity *= 2;
            T *temp = new T[capacity];
            memcpy(temp, array, size * sizeof(T));
            delete[] array;
            array = temp;
        }

        array[size++] = value;
    }

    void pop_back()
    {
        if (size > 0)
        {
            --size;
        }
    }

    T &operator[](int index)
    {
        return array[index];
    }

    const T &operator[](int index) const
    {
        return array[index];
    }


    int getSize() const
    {
        return size;
    }

        T* begin() {
        return array;
    }

    const T* begin() const {
        return array;
    }

    T* end() {
        return array + size;
    }

    const T* end() const {
        return array + size;
    }

};
