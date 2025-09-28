#include "node.h"

template<typename T>
Node<T>::Node(const T& d) : dato(d), siguiente(nullptr) {}