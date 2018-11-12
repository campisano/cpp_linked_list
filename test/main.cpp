#include <iostream>
#include <node.hpp>
#include <sstream>
#include <string>

void append(Node * _node, const int _val)
{
    Node * end = _node;

    while(end->next != NULL)
    {
        end = end->next;
    }

    end->next = new Node(_val, NULL);
}

std::string toString(Node * _node)
{
    std::stringstream ss;

    for(Node * i = _node; i != NULL; i = i->next)
    {
        ss << '[' << i->value << ']';
    }

    return ss.str();
}

void free(Node * _head)
{
    Node * to_delete;
    Node * i = _head;

    while(i != NULL)
    {
        to_delete = i;
        i = i->next;
        delete to_delete;
    }
}

int main() {
    std::cout << "main" << std::endl;

    Node * n = new Node(1, NULL);
    append(n, 2);
    append(n, 3);
    append(n, 4);
    append(n, 5);
    append(n, 6);
    append(n, 1);
    append(n, 2);
    append(n, 3);
    append(n, 4);
    append(n, 5);
    append(n, 6);

    std::cout << toString(n) << std::endl;

    Node * it;

    int i = 0;
    for(it = n; it != NULL; it = it->next)
    {
        std::cout << i++ << ": " << it->value <<  std::endl;
    }

    free(n);

    return 0;
}
