#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T dato;
        Node<T>* siguiente, * anterior;

        Node(const T& d);
    };

#endif // NODE_H