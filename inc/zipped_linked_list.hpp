#ifndef ZIPPED_LINKED_LIST__HPP
#define ZIPPED_LINKED_LIST__HPP

#include <extendible_linked_list.hpp>

namespace containers_pp
{
template <typename T>
class ReferenceNode : public Node<T>
{
public:
    explicit ReferenceNode(
        T & _value, Node<T> * _prev, Node<T> * _next) :
        m_value(_value), m_prev(_prev), m_next(_next) {}

    virtual ~ReferenceNode() {}

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
    T & m_value;
    Node<T> * m_prev;
    Node<T> * m_next;
};

template <typename T>
class ZippedLinkedList : public ExtendibleLinkedList<T>
{
public:
    explicit ZippedLinkedList() {}
    virtual ~ZippedLinkedList() {}

    virtual void cloneZip(const ExtendibleLinkedList<T> & _orig)
    {
        Node<T> * existent;
        for(It<T> it = _orig.first(); it != _orig.end(); ++it)
        {
            existent = this->get(*it);
            if(! existent)
            {
                std::cout << "copied" << std::endl;
                this->append(*it);
            }
            else
            {
                std::cout << "referenced" << std::endl;
                if(this->m_first == NULL)
                {
                    this->m_first = this->m_last =
                                        new ReferenceNode<T>(*it, NULL, NULL);
                }
                else
                {
                    this->m_last->next(
                        new ReferenceNode<T>(
                            existent->value(), this->m_last, NULL));
                    this->m_last = this->m_last->next();
                }
            }
        }
    }

private:
    virtual Node<T> * get(const T & _val) const
    {
        if(this->m_first)
        {
            Node<T> * it;

            for(it = this->m_first; it != this->m_last; it = it->next())
            {
                if(it->value() == _val)
                {
                    return it;
                }
            }
        }

        if(this->m_last)
        {
            if(this->m_last->value() == _val)
            {
                return this->m_last;
            }
        }

        return NULL;
    }
};
}

#endif
