#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include "../node/node.cpp"
#include <stdexcept>
#pragma once
using namespace std;

template <typename T>
class ArrayList {

public:
    Node<T> *cabeza;
    int count;
    Node<T> *actual;

    ArrayList();
    ~ArrayList();

    void add(const T& Object);

    T get(int index) const;

    void set(int index, const T& object);

    T remove(int index);

    void Delete(int index);

    int size() const;

    T first();

    T next();

    T priore();

    T last();
    
    void viewList();


};

#endif // ARRAYLIST_H