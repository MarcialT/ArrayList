#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#pragma once
using namespace std;

template <typename T>
class ArrayList {
private:
    T* data;
    int capacity;
    int count;

public:
    ArrayList(int initialCapacity = 10);
    ~ArrayList();

    void add(const T& Object);

    T get(int index) const;

    void set(int index, const T& object);

    T remove(int index);

    void Delete(int index);

    int size() const;
};

#endif // ARRAYLIST_H