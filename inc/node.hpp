#ifndef NODE__HPP
#define NODE__HPP

#include <iostream>

struct Node
{
    explicit Node(int _value, Node * _next) : value(_value), next(_next)
    {
        std::cout << "Node()" << std::endl;
    }
    virtual ~Node()
    {
        std::cout << "~Node()" << std::endl;
    }

    int value;
    Node * next;
};

#endif
