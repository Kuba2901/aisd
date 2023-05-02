#pragma once
#include <iostream>
#include <cstring>
#include "CustomVector.h"

template <typename T>
class CustomQueue
{
private:
    CustomVector<T> vec;

public:
    void push(T value)
    {
        vec.push_back(value);
    }

    void pop()
    {
        for (int i = 0; i < vec.getSize() - 1; i++)
        {
            vec[i] = vec[i + 1];
        }
        vec.pop_back();
    }

    T front() const
    {
        return vec[0];
    }

    int getSize() const
    {
        return vec.getSize();
    }

    bool empty() const
    {
        return vec.getSize() == 0;
    }
};
