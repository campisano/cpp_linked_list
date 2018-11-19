#include <iostream>
#include <linked_list.hpp>

class Foo
{
public:
    explicit Foo() : m_counter(Foo::counter++)
    {
        std::cout << "Foo(" << m_counter << ")\t" << this << std::endl;
    }

    explicit Foo(uint32_t _value) : m_counter(_value)
    {
        std::cout << "Foo=(" << m_counter << ")\t" << this << std::endl;
    }

    explicit Foo(const Foo & _other) : m_counter(_other.m_counter)
    {
        std::cout << "Foo = Foo(" << m_counter << ")\t" << this << std::endl;
    }

    ~Foo()
    {
        std::cout << "~Foo(" << m_counter << ")\t" << this << std::endl;
    }

    inline bool operator==(const Foo & _other)
    {
        return (this->m_counter == _other.m_counter);
    }

    friend std::ostream& operator<<(std::ostream & _os, const Foo & _foo)
    {
        _os << _foo.m_counter;

        return _os;
    }
private:
    uint32_t m_counter;
    static uint32_t counter;
};

uint32_t Foo::counter = 0;

typedef containers::LinkedList<Foo> LLi;
typedef containers::It<Foo> Iti;

int main() {
    std::cout << "main" << std::endl;

    LLi ll;

    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    // ll.append(Foo());
    ll.append(Foo());
    ll.append(Foo(0));
    ll.prepend(Foo());
    // ll.prepend(Foo());
    // ll.prepend(Foo());
    // ll.prepend(Foo());
    // ll.prepend(Foo());
    // ll.prepend(Foo());

    std::cout << ll.toString() << std::endl;

    Iti it;

    int i = 0;
    for(it = ll.first(); it != ll.end(); ++it)
    {
        std::cout << "ll[" << i++ << "]:\t" << *it <<  std::endl;
    }

    // i--;
    // for(it = ll.last(); it != ll.end(); --it)
    // {
    //     std::cout << "ll[" << i-- << "]:\t" << *it <<  std::endl;
    // }

    return 0;
}
