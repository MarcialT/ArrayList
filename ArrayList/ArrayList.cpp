
#include"ArrayList.h"
#pragma once

template<typename T> 
ArrayList<T>::ArrayList() : cabeza(nullptr), count(0), actual(nullptr){}

template<typename T>
ArrayList<T>::~ArrayList(){
    while (cabeza){
        Node<T>* temp =cabeza;
        cabeza = cabeza -> siguiente;
        delete temp;
    }
    
}

template<typename T>
void ArrayList<T>::add(const T& Object){
     Node<T>* nuevo = new Node<T> (Object);
     if (cabeza == nullptr){
        cabeza = nuevo;
     } else {
        Node<T>* aux = cabeza;
        while (aux -> siguiente != nullptr){
            aux = aux -> siguiente;
        }
        aux -> siguiente = nuevo;
     }
     count++;
}

template<typename T>
T ArrayList<T>::get(int index) const{
   if  (index < 0 || index >= count ) throw out_of_range("Indice fuera de rango");
   Node<T>* aux = cabeza;
   for (int i = 0; i < index; ++i) {
    aux = aux -> siguiente;
    }
    return aux -> dato;
}

template<typename T>
void ArrayList<T>::set(int index, const T& object){
    if (index < 0 || index >= count) throw out_of_range("indice fuera de rango");
    Node<T>* aux = cabeza;
    for ( int i = 0; i < index; ++i){
        aux = aux -> siguiente;
    }
    aux -> dato =  object;
}

template<typename T>
T ArrayList<T>::remove(int index){
    if (index < 0 || index >= count) throw out_of_range("indice fuera de rango");
    Node<T>* temp;
    T valor;
    if (index == 0){
        temp = cabeza;
        cabeza =  cabeza -> siguiente;
        valor = temp -> dato;
        delete temp;
    } else {
        Node<T>* aux = cabeza;
        for (int i = 0; i < index - 1; ++i){
            aux = aux -> siguiente;
        }
        temp = aux -> siguiente;
        aux -> siguiente = temp -> siguiente;
        valor = temp -> dato;
        delete temp;
    }
    count --;
    return valor;
}

template<typename T>
void ArrayList<T>::Delete(int index){
    remove(index);
   
}

template<typename T>
int ArrayList<T>::size() const{
    return count;
}

template<typename T>
T ArrayList<T>::first(){
    actual = cabeza;
    if (actual == nullptr){
        throw out_of_range("La lista esta vacia.");
 }
    return actual->dato;
}


template<typename T>
T ArrayList<T>::next(){
    if (actual == nullptr)
        throw out_of_range("La lista esta vacia.");
    if (actual->siguiente == nullptr) {
        actual = nullptr; 
        throw out_of_range("No hay siguiente nodo.");
    }
    actual = actual->siguiente;
    return actual->dato;
}


template<typename T>
T ArrayList<T>::priore(){
     if(actual == nullptr)
        throw out_of_range("La lista esta vacia");
    if(actual == cabeza) 
        throw out_of_range("No hay nodo anterior.");

    Node<T>* aux = cabeza;
    while (aux -> siguiente != actual){
        aux = aux -> siguiente;
    }
    actual = aux;
    return actual -> dato;
}


template<typename T>
T ArrayList<T>::last(){
    if(cabeza == nullptr){
        throw out_of_range("La lista esta vacia");
    }
    actual = cabeza;
    while (actual -> siguiente != nullptr){
        actual = actual -> siguiente;
    }
    return actual -> dato;
    }


template<typename T>
void ArrayList<T>::viewList(){
    try {
        cout << first() << " ";
        while (true) {
            cout << next() << " ";
        }
    } catch (const out_of_range& e) {
        cout << endl;
    }

}


