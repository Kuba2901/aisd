#pragma once
#include "CustomVector.h"

template <typename T>
class CustomHashMap
{
private:
    static const int CAPACITY = 100;

    class CustomPair {
    public:
        int key;
        T value;

        CustomPair(int k, const T& v) : key(k), value(v) {}
    };

    CustomVector<CustomPair> buckets[CAPACITY];

public:
    void insert(int key, const T& value)
    {
        int index = key % CAPACITY;
        for (auto& pair : buckets[index])
        {
            if (pair.key == key)
            {
                pair.value = value;
                return;
            }
        }
        buckets[index].push_back(CustomPair(key, value));
    }

    T* get(int key) 
    {
        int index = key % CAPACITY;
        for (const typename CustomHashMap<T>::CustomPair& pair : buckets[index])

        {
            if (pair.key == key)
            {
                return &pair.value;
            }
        }
        return nullptr;
    }



    // bool remove(int key)
    // {
    //     int index = key % CAPACITY;
    //     for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it)
    //     {
    //         if (it->key == key)
    //         {
    //             // buckets[index].erase(it);
    //             return true;
    //         }
    //     }
    //     return false;
    // }
};