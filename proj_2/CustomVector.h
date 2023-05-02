#pragma once

template <typename T>
class CustomVector
{
private:
    T *data;
    int capacity;
    int size;

    void resize(int newCapacity)
    {
        T *newData = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    CustomVector() : data(nullptr), capacity(0), size(0) {}

    CustomVector(int initialCapacity) : data(new T[initialCapacity]), capacity(initialCapacity), size(0) {}

    CustomVector(int initialCapacity, const T &initialValue = T()) : data(new T[initialCapacity]), capacity(initialCapacity), size(initialCapacity)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = initialValue;
        }
    }

    CustomVector(const CustomVector &other) : data(new T[other.capacity]), capacity(other.capacity), size(other.size)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    CustomVector(CustomVector &&other) : data(other.data), capacity(other.capacity), size(other.size)
    {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }

    ~CustomVector()
    {
        delete[] data;
    }

    CustomVector &operator=(const CustomVector &other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new T[other.capacity];
            capacity = other.capacity;
            size = other.size;
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    CustomVector &operator=(CustomVector &&other)
    {
        if (this != &other)
        {
            delete[] data;
            data = other.data;
            capacity = other.capacity;
            size = other.size;
            other.data = nullptr;
            other.capacity = 0;
            other.size = 0;
        }
        return *this;
    }

    void push_back(const T &element)
    {
        if (size == capacity)
        {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = element;
    }

    void push_back(T *element)
    {
        if (size == capacity)
        {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = element;
    }

    void pop_back()
    {
        if (size > 0)
        {
            size--;
        }
    }

    T &operator[](int index)
    {
        return data[index];
    }

    const T &operator[](int index) const
    {
        return data[index];
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    T *begin() const
    {
        return data;
    }

    T *end() const
    {
        return data + size;
    }

    void pop_front()
    {
        if (size > 0)
        {
            for (int i = 0; i < size - 1; i++)
            {
                data[i] = data[i + 1];
            }
            size--;
        }
    }

    void insert(const T &element, int index)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity)
        {
            resize(capacity == 0 ? 1 : capacity * 2);
        }
        for (int i = size - 1; i >= index; i--)
        {
            data[i + 1] = data[i];
        }
        data[index] = element;
        size++;
    }

    bool empty()
    {
        return size > 0;
    }
};
