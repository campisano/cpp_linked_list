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
        explicit Node() : next(NULL) {std::cout << "Node(" << value << ")" << std::endl;}
        virtual ~Node() {std::cout << "~Node(" << value << ")" << std::endl;}
        T value;
        Node * next;
    };

    template <typename T>
    class It
    {
    public:
        explicit It() : current(NULL) {}
        explicit It(Node<T> * _node) : current(_node) {}

        bool operator !=(const It<T> & _node) const
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
        Node<T> * current;
    };

    template <typename T>
    class LinkedList
    {
    public:
        explicit LinkedList();
        virtual ~LinkedList();

        It<T> start() const;
        It<T> end() const;

        void append(const T _val);

        std::string toString() const;

    private:
        Node<T> * m_start;
        Node<T> * m_end;
    };

    template<typename T>
    LinkedList<T>::LinkedList()
    {
        // TODO nosense an empty node, node should ever have a value in the constructor call
        m_end = new Node<T>();
        m_start = m_end;
    }

    template<typename T>
    LinkedList<T>::~LinkedList()
    {
        const Node<T> * to_del;
        const Node<T> * i = m_start;
        while(i != m_end)
        {
            to_del = i;
            i = i->next;
            delete to_del;
        }

        delete m_end;
    }

    template<typename T>
    It<T> LinkedList<T>::start() const {
        return It<T>(m_start);
    }

    template<typename T>
    It<T> LinkedList<T>::end() const {
        return It<T>(m_end);
    }

    template<typename T>
    std::string LinkedList<T>::toString() const {
        std::stringstream ss;

        for(It<T> it = start(); it != end(); ++it)
        {
            ss << '[' << *it << ']';
        }

        return ss.str();
    }

    template <typename T>
    void LinkedList<T>::append(const T _val) {
        m_end->value = _val;
        m_end->next = new Node<T>();
        m_end = m_end->next;
    }
}

#endif
