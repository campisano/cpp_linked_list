#ifndef EXTENDIBLE_LINKED_LIST__HPP
#define EXTENDIBLE_LINKED_LIST__HPP

#include <cstdint>
#include <sstream>
#include <string>

namespace containers_pp
{
template <typename T>
class Node
{
public:
    virtual ~Node() {};

    virtual T & value() = 0;
    virtual Node * prev() = 0;
    virtual void prev(Node * _node) = 0;
    virtual Node * next() = 0;
    virtual void next(Node * _node) = 0;
};

template <typename T>
class It
{
public:
    explicit It() : m_node(NULL) {}
    explicit It(Node<T> * _node) : m_node(_node) {}
    virtual ~It() {}

    virtual bool operator !=(const It<T> & _other) const
    {
        return m_node != _other.m_node;
    }

    virtual It & operator ++()
    {
        if(m_node)
        {
            m_node = m_node->next();
        }
        return * this;
    }

    virtual It & operator --()
    {
        if(m_node)
        {
            m_node = m_node->prev();
        }
        return * this;
    }

    virtual T & operator*() const
    {
        return m_node->value();
    }
private:
    Node<T> * m_node;
};

template <typename T>
class InstanceNode : public Node<T>
{
public:
    explicit InstanceNode(
        const T & _value, Node<T> * _prev, Node<T> * _next) :
        m_value(_value), m_prev(_prev), m_next(_next) {}

    virtual ~InstanceNode() {}

    virtual inline T & value()
    {
        return m_value;
    }
    virtual inline Node<T> * prev()
    {
        return m_prev;
    }
    virtual inline void prev(Node<T> * _node)
    {
        m_prev = _node;
    }
    virtual inline Node<T> * next()
    {
        return m_next;
    }
    virtual inline void next(Node<T> * _node)
    {
        m_next = _node;
    }

private:
    T m_value;
    Node<T> * m_prev;
    Node<T> * m_next;
};


template <typename T>
class ExtendibleLinkedList
{
public:
    explicit ExtendibleLinkedList() :
        m_first(NULL), m_last(NULL), m_size(0) {}

    virtual ~ExtendibleLinkedList()
    {
        const Node<T> * to_delete;
        Node<T> * i = m_first;
        while(i != NULL)
        {
            to_delete = i;
            i = i->next();
            delete to_delete;
        }
    }

    virtual It<T> first() const
    {
        return It<T>(m_first);
    }
    virtual It<T> last() const
    {
        return It<T>(m_last);
    }
    virtual It<T> end() const
    {
        return It<T>(NULL);
    }

    virtual void append(const T & _val)
    {
        if(m_first == NULL)
        {
            m_first = m_last = new InstanceNode<T>(_val, NULL, NULL);
        }
        else
        {
            m_last->next(new InstanceNode<T>(_val, m_last, NULL));
            m_last = m_last->next();
        }

        ++m_size;
    }

    virtual void prepend(const T & _val)
    {
        if(m_first == NULL)
        {
            m_first = m_last = new InstanceNode<T>(_val, NULL, NULL);
        }
        else
        {
            m_first->prev(new InstanceNode<T>(_val, NULL, m_first));
            m_first = m_first->prev();
        }

        ++m_size;
    }

    virtual std::string toString() const
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

    virtual uint64_t size() const
    {
        return m_size;
    }

    virtual bool contains(const T & _val) const
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

protected:
    Node<T> * m_first;
    Node<T> * m_last;
    uint64_t m_size;
};
}

#endif
