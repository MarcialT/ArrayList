#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* data;
    int tail;
    int capacity;

public:
    ArrayList(int initialCapacity = 10) {
        data = new T[initialCapacity];
        tail = 0;
        capacity = initialCapacity;
    }

    ~ArrayList() {
        delete[] data;
    }

    void add(const T& value) {
        if (tail >= capacity) {
            int newCapacity = capacity * 2;
            T* newData = new T[newCapacity];
            for (int i = 0; i < tail; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = newCapacity;
        }
        data[tail++] = value;
    }
};

#endif // ARRAYLIST_H