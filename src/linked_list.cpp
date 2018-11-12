#include <linked_list.hpp>

#include <sstream>

using namespace containers;

LinkedList::LinkedList()
{
    // TODO template class
    // TODO nosense an empty node, node should ever have a value in the constructor call
    m_end = new Node();
    m_start = m_end;
}

LinkedList::~LinkedList()
{
    const Node * to_del;
    const Node * i = m_start;
    while(i != m_end)
    {
        to_del = i;
        i = i->next;
        delete to_del;
    }

    delete m_end;
}

It LinkedList::start() const {
    return It(m_start);
}

It LinkedList::end() const {
    return It(m_end);
}

std::string LinkedList::toString() const {
    std::stringstream ss;

    for(It it = start(); it != end(); ++it)
    {
        ss << '[' << *it << ']';
    }

    return ss.str();
}

void LinkedList::append(const T _val) {
    m_end->value = _val;
    m_end->next = new Node();
    m_end = m_end->next;
}
