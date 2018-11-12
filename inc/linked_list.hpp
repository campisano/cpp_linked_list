#ifndef LINKED_LIST__HPP
#define LINKED_LIST__HPP

#include <iostream>
#include <sstream>
#include <string>

namespace containers
{
    template <typename T>
    struct Node
    {
        explicit Node(T _value, Node * _next) : value(_value), next(_next)
        {
            std::cout << "Node(" << value << ")" << std::endl;
        }
        virtual ~Node()
        {
            std::cout << "~Node(" << value << ")" << std::endl;
        }
        T value;
        Node * next;
    };

    template <typename T>
    class It
    {
    public:
        explicit It() : node(NULL) {}
        explicit It(Node<T> * _node) : node(_node) {}

        bool operator !=(const It<T> & _other) const
        {
            return node != _other.node;
        }

        It & operator ++()
        {
            if (node) node = node->next;
            return * this;
        }

        T operator*()
        {
            return node->value;
        }
    private:
        Node<T> * node;
    };

    template <typename T>
    class LinkedList
    {
    public:
        explicit LinkedList() : m_start(NULL), m_end(NULL) {}
        virtual ~LinkedList()
        {
            const Node<T> * to_delete;
            const Node<T> * i = m_start;
            while(i != NULL)
            {
                to_delete = i;
                i = i->next;
                delete to_delete;
            }
        }

        It<T> start() const { return It<T>(m_start); }
        It<T> end() const { return It<T>(m_end); }

        void append(const T _val)
        {
            if(m_start == NULL) {
                m_start = m_end = new Node<T>(_val, NULL);
            }
            else
            {
                m_end->next = new Node<T>(_val, NULL);
                m_end = m_end->next;
            }
        }

        std::string toString() const
        {
            std::stringstream ss;

            for(It<T> it = start(); it != end(); ++it)
            {
                ss << '[' << *it << ']';
            }

            return ss.str();
        }

    private:
        Node<T> * m_start;
        Node<T> * m_end;
    };
}

#endif
