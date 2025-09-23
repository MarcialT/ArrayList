#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* data;
    int capacity;
    int count;

public:
    ArrayList(int initialCapacity = 10) {
        capacity = initialCapacity;
        data = new T[capacity];
        count = 0;
    }

    ~ArrayList() {
        delete[] data;
    }

    void add(const T& Object) {

        if (count == capacity) {
            T* newData = new T[capacity*2];
            for (int i = 0; i < count; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
            capacity = capacity*2;
            }

        data[count++] = Object;
    }

    T get(int index) const {
        if (index < 0  || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }

    void set(int index, const T& object) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = object;
    }

    T remove(int index) {
        if (index < 0  || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        T removeElement = data[index];
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        count--;
        return removeElement;
    }

    void Delete(int index) {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        count--;
    }

    int size() const {
        return count;
    }
};

#endif // ARRAYLIST_H