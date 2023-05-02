#pragma once
#include "CustomVector.h"

template <typename T>
class CustomQueue
{
private:
    CustomVector<T> data_;

public:
    CustomQueue() {}

    bool empty() const
    {
        return data_.empty();
    }

    int size() const
    {
        return data_.size();
    }

    void push(const T &value)
    {
        data_.push_back(value);
    }

    void pop()
    {
        data_.erase(data_.begin());
    }

    T &front()
    {
        return data_.front();
    }

    const T &front() const
    {
        return data_.front();
    }

    T &back()
    {
        return data_.back();
    }

    const T &back() const
    {
        return data_.back();
    }
};
