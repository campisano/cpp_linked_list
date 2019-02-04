#ifndef LINKED_LIST__HPP
#define LINKED_LIST__HPP

#include <cstdint>
#include <sstream>
#include <string>

namespace containers
{
template <typename T>
struct Node
{
    explicit Node(
        const T & _value, Node * _prev, Node * _next) :
        value(_value), prev(_prev), next(_next) {}

    ~Node() {}

    T value;
    Node * prev;
    Node * next;
};

template <typename T>
class It
{
public:
    explicit It() : m_node(NULL) {}
    explicit It(Node<T> * _node) : m_node(_node) {}

    bool operator !=(const It<T> & _other) const
    {
        return m_node != _other.m_node;
    }

    It & operator ++()
    {
        if(m_node)
        {
            m_node = m_node->next;
        }
        return * this;
    }

    It & operator --()
    {
        if(m_node)
        {
            m_node = m_node->prev;
        }
        return * this;
    }

    T & operator*() const
    {
        return m_node->value;
    }
private:
    Node<T> * m_node;
};

template <typename T>
class LinkedList
{
public:
    explicit LinkedList() : m_first(NULL), m_last(NULL), m_size(0) {}

    ~LinkedList()
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

    It<T> first() const
    {
        return It<T>(m_first);
    }
    It<T> last() const
    {
        return It<T>(m_last);
    }
    It<T> end() const
    {
        return It<T>(NULL);
    }

    void append(const T & _val)
    {
        if(m_first == NULL)
        {
            m_first = m_last = new Node<T>(_val, NULL, NULL);
        }
        else
        {
            m_last->next = new Node<T>(_val, m_last, NULL);
            m_last = m_last->next;
        }

        ++m_size;
    }

    void prepend(const T & _val)
    {
        if(m_first == NULL)
        {
            m_first = m_last = new Node<T>(_val, NULL, NULL);
        }
        else
        {
            m_first->prev = new Node<T>(_val, NULL, m_first);
            m_first = m_first->prev;
        }

        ++m_size;
    }

    std::string toString() const
    {
        std::stringstream ss;
        ss << '[';
        It<T> it, last = this->last();

        for(it = first(); it != last; ++it)
        {
            ss << *it << ',';
        }

        ss << *this->last() << ']';

        return ss.str();
    }

    uint64_t size() const
    {
        return m_size;
    }

    bool contains(const T & _val) const
    {
        for(It<T> it = first(); it != end(); ++it)
        {
            if(*it == _val)
            {
                return true;
            }
        }

        return false;
    }

private:
    Node<T> * m_first;
    Node<T> * m_last;
    uint64_t m_size;
};
}

#endif
