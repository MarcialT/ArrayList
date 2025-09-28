
#include"ArrayList.h"

template<typename T> 
ArrayList<T>::ArrayList() : cabeza(nullptr), count(0), actual(nullptr){}

template<typename T>
ArrayList<T>::~ArrayList(){
    while (cabeza){
        Node* temp =cabeza;
        cabeza = cabeza -> siguiente;
        delete temp;
    }
    
}

template<typename T>
void ArrayList<T>::add(const T& Object){
     Node* nuevo = new Nodo (Object);
     if (cabeza == nullptr){
        cabeza = nuevo;
     } else {
        Node* aux = cabeza;
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
   Node* aux = cabeza;
   for (int i = 0; i < index; ++i) {
    aux = aux -> siguiente;
    }
    return aux -> dato;
}

template<typename T>
void ArrayList<T>::set(int index, const T& object){
    if (index < 0 || index >= count) throw out_of_range("indice fuera de rango");
    Node* aux = cabeza;
    for ( int i = 0; i < index; ++i){
        aux = aux -> siguiente;
    }
    aux -> dato =  object;
}

template<typename T>
T ArrayList<T>::remove(int index){
    if (index < 0 || index >= count) throw out_of_range("indice fuera de rango");
    Node* temp;
    T valor;
    if (index == 0){
        temp = cabeza;
        cabeza =  cabeza -> siguiente;
        valor = temp -> dato;
        delete temp;
    } else {
        Node* aux = cabeza;
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
        throw out_of_range("La lista está vacía.");
 }
    return actual->dato;
}

template<typename T>
T ArrayList<T>::next(){
    if (actual == nullptr)
        throw out_of_range("La lista está vacía.");
    if (actual -> siguiente == nullptr)
        throw out_of_range("No hay siguiente nodo.");
    
    actual = actual -> siguiente;
    return actual -> dato;
    }



template<typename T>
T ArrayList<T>::priore(){

}

template<typename T>
T ArrayList<T>::last(){

}

template<typename T>
T ArrayList<T>::viewList(){

}

template<typename T>
T ArrayList<T>::viewReverseList(){

}

