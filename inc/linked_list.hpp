#ifndef LINKED_LIST__HPP
#define LINKED_LIST__HPP

#include <iostream>
#include <string>

namespace containers
{
    typedef int T;
    struct Node
    {
        explicit Node() : next(NULL) {std::cout << "Node()" << std::endl;}
        virtual ~Node() {std::cout << "~Node(" << value << ")" << std::endl;}
        T value;
        Node * next;
    };

    class It
    {
    public:
        explicit It() : current(NULL) {}
        explicit It(Node * _node) : current(_node) {}

        bool operator !=(const It & _node) const
        {
            return current != _node.current;
        }

        It & operator ++()
        {
            if (current) current = current->next;
            return * this;
        }

        T operator*()
        {
            return current->value;
        }
    private:
        Node * current;
    };

    class LinkedList
    {
    public:
        explicit LinkedList();
        virtual ~LinkedList();

        It start() const;
        It end() const;

        void append(const T _val);

        std::string toString() const;

    private:
        Node * m_start;
        Node * m_end;
    };
}

#endif
