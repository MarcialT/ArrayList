#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>
using namespace std;

template <typename T>

class ArrayList {

private:
    T* array = NULL;
    int size;

public:

    ArrayList() {
        this->array = new T[size];
    }

    ArrayList(T data){
        this->array = new T[size]
        add(data);
    }

    ~ArrayList() {
        delete[] data;
    }

    void add(const T& value) {
        this->size++;
       
    }

    T get (T index) {
          
    }

    void set(T index, T object){

    }

    T remove(T index){

    }

    void Delete(T index){

    }

    int size(){
        cout<<this->size<<endl;
    }

};

#endif // ARRAYLIST_H