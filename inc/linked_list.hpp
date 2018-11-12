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
        explicit Node(T _value, Node* _prev, Node * _next) :
            value(_value), prev(_prev), next(_next)
        {
            std::cout << "Node(" << value << ")" << std::endl;
        }

        virtual ~Node()
        {
            std::cout << "~Node(" << value << ")" << std::endl;
        }

        T value;
        Node * prev;
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

        It & operator --()
        {
            if (node) node = node->prev;
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
        explicit LinkedList() : m_first(NULL), m_last(NULL) {}

        virtual ~LinkedList()
        {
            const Node<T> * to_delete;
            const Node<T> * i = m_first;
            while(i != NULL)
            {
                to_delete = i;
                i = i->next;
                delete to_delete;
            }
        }

        It<T> first() const { return It<T>(m_first); }
        It<T> last() const { return It<T>(m_last); }
        It<T> end() const { return It<T>(NULL); }

        void append(const T _val)
        {
            if(m_first == NULL) {
                m_first = m_last = new Node<T>(_val, NULL, NULL);
            }
            else
            {
                m_last->next = new Node<T>(_val, m_last, NULL);
                m_last = m_last->next;
            }
        }

        void prepend(const T _val)
        {
            if(m_first == NULL) {
                m_first = m_last = new Node<T>(_val, NULL, NULL);
            }
            else
            {
                m_first->prev = new Node<T>(_val, NULL, m_first);
                m_first = m_first->prev;
            }
        }

        std::string toString() const
        {
            std::stringstream ss;

            for(It<T> it = first(); it != end(); ++it)
            {
                ss << '[' << *it << ']';
            }

            return ss.str();
        }

    private:
        Node<T> * m_first;
        Node<T> * m_last;
    };
}

#endif
