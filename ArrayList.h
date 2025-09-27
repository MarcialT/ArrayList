#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
#include <stdexcept>
#pragma once
using namespace std;

template <typename T>
class ArrayList {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
        Nodo(const T& d);
    };
    Nodo *cabeza;
    int count;
    Nodo *actual;

   
public:
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
    
    T viewList();

    T viewReverseList();

};

#endif // ARRAYLIST_H