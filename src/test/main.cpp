#include <iostream>
#include <extendible_linked_list.hpp>
#include <linked_list.hpp>
#include <zipped_linked_list.hpp>


void test_linked_list();
void test_extended_list();
void test_zipped_list();

// TODO
// - array intersection
// - tree-like ordered list
int main()
{
    test_linked_list();
    test_extended_list();
    test_zipped_list();

    return 0;
}

class Foo
{
public:
    explicit Foo() : m_counter(--Foo::counter)
    {
        std::cout << "const Foo()" << m_counter << "\t" << this << std::endl;
    }

    explicit Foo(int32_t _value) : m_counter(_value)
    {
        std::cout << "const Foo(" << m_counter << ")\t" << this << std::endl;
    }

    explicit Foo(const Foo & _other) : m_counter(_other.m_counter)
    {
        std::cout << "copy Foo=Foo(" << m_counter << ")\t" << this << std::endl;
    }

    ~Foo()
    {
        std::cout << " destr ~Foo(" << m_counter << ")\t" << this << std::endl;
    }

    inline bool operator==(const Foo & _other)
    {
        return (this->m_counter == _other.m_counter);
    }

    friend std::ostream & operator<<(std::ostream & _os, const Foo & _foo)
    {
        _os << "{'val':" << _foo.m_counter << ", 'ref':" << & _foo << '}';

        return _os;
    }

private:
    int32_t m_counter;
    static int32_t counter;
};

int32_t Foo::counter = 0;

// void cloneZip(const LLi & _orig, LLi & _new)
// {
//     for(Iti it = _orig.first(); it != _orig.end(); ++it)
//     {
//         if(! _new.contains(*it))
//         {
//             _new.append(*it);
//         }
//     }
// }

void test_linked_list()
{
    std::cout << "= test linked list <int> =" << std::endl;

    containers::LinkedList<int> ll;
    std::cout << "appending {1,2,3,4,5,6,1,2,3,4,5,6}" << std::endl;
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);
    ll.append(6);
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);
    ll.append(6);
    std::cout << "prepending {1,2,3,4,5,6}" << std::endl;
    ll.prepend(1);
    ll.prepend(2);
    ll.prepend(3);
    ll.prepend(4);
    ll.prepend(5);
    ll.prepend(6);

    std::cout << "linked list:" << std::endl;
    std::cout << ll.toString() << std::endl;

    containers::It<int> it;

    std::cout << "looping:" << std::endl;
    int i = 0;
    for(it = ll.first(); it != ll.end(); ++it)
    {
        std::cout << "ll[" << i++ << "]:\t" << *it <<  std::endl;
    }

    std::cout << "reverse looping:" << std::endl;
    i--;
    for(it = ll.last(); it != ll.end(); --it)
    {
        std::cout << "ll[" << i-- << "]:\t" << *it <<  std::endl;
    }

    std::cout << "= ~test linked list <int> =" << std::endl;
}

void test_extended_list()
{
    std::cout << "= test extended list <Foo> =" << std::endl;

    containers_pp::ExtendibleLinkedList<Foo> ll;
    std::cout << "appending {F0,F1,F0}" << std::endl;
    ll.append(Foo(0));
    ll.append(Foo(1));
    ll.append(Foo(0));
    std::cout << "prepending {F2}" << std::endl;
    ll.prepend(Foo(2));

    std::cout << "extendible list:" << std::endl;
    std::cout << ll.toString() << std::endl;

    std::cout << "= ~test extended list <Foo> =" << std::endl;
}

void test_zipped_list()
{
    std::cout << "= test zipped list <Foo> =" << std::endl;

    containers_pp::ExtendibleLinkedList<Foo> ll;
    std::cout << "appending {F0,F1,F0}" << std::endl;
    ll.append(Foo(0));
    ll.append(Foo(1));
    ll.append(Foo(0));
    std::cout << "prepending {F2}" << std::endl;
    ll.prepend(Foo(2));

    std::cout << "extendible list:" << std::endl;
    std::cout << ll.toString() << std::endl;

    std::cout << "cloning zipped:" << std::endl;
    containers_pp::ZippedLinkedList<Foo> llc;
    llc.cloneZip(ll);

    std::cout << "zipped cloned list:" << std::endl;
    std::cout << llc.toString() << std::endl;

    std::cout << "= ~test zipped list <Foo> =" << std::endl;
}
