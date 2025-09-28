#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

template <typename T>
class Node {
    private:
        T dato;
        Node* siguiente;
    public:
        Node(const T& d);
    };

#endif // NODE_H