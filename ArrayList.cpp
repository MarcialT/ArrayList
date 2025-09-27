
#include"ArrayList.h"


template<typename T>
ArrayList<T>::Nodo::Nodo(const T& d) : dato(d), siguiente(nullptr) {}

template<typename T> 
ArrayList<T>::ArrayList() : cabeza(nullptr), count(0){}

template<typename T>
ArrayList<T>::~ArrayList(){
    while (cabeza){
        Nodo* temp =cabeza;
        cabeza = cabeza -> siguiente;
        delete temp;
    }
    
}

template<typename T>
void ArrayList<T>::add(const T& Object){
     Nodo* nuevo = new Nodo (Object);
     if (cabeza == nullptr){
        cabeza = nuevo;
     } else {
        Nodo* aux = cabeza;
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
   Nodo* aux = cabeza;
   for (int i = 0; i < index; ++i) {
    aux = aux -> siguiente;
    }
    return aux -> dato;
}

template<typename T>
void ArrayList<T>::set(int index, const T& object){
    if (index < 0 || index >= count) throw out_of_range("indice fuera de rango");
    Nodo* aux = cabeza;
    for ( int i = 0; i < index; ++i){
        aux = aux -> siguiente;
    }
    aux -> dato =  object;
}

template<typename T>
T ArrayList<T>::remove(int index){
    if (index < 0 || index >= count) throw out_of_range("indice fuera de rango");
    Nodo* temp;
    T valor;
    if (index == 0){
        temp = cabeza;
        cabeza =  cabeza -> siguiente;
        valor = temp -> dato;
        delete temp;
    } else {
        Nodo* aux = cabeza;
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