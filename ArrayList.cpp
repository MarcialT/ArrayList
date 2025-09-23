#include<iostream>
#include <stdexcept>
#include"ArrayList.h"

using namespace std;

template<class T>
ArrayList<T>::ArrayList(int InitialCapacity){
    capacity = InitialCapacity;
        data = new T[capacity];
        count = 0;
}

template<class T>
ArrayList<T>::~ArrayList(){
    delete[] data;
}

template<class T>
void ArrayList<T>::add(const T& Object){
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

template<class T>
T ArrayList<T>::get(int index) const{
    if (index < 0  || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
}

template<class T>
void ArrayList<T>::set(int index, const T& object){
    if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        data[index] = object;
}

template<class T>
T ArrayList<T>::remove(int index){
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

template<class T>
void ArrayList<T>::Delete(int index){
    if (index < 0 || index >= count) {
            throw std::out_of_range("Index out of bounds");
        }
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        count--;
}

template<class T>
int ArrayList<T>::size() const{
    return count;
}