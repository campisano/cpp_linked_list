#include <iostream>
#include <linked_list.hpp>

typedef containers::LinkedList<int> LLi;
typedef containers::It<int> Iti;

int main() {
    std::cout << "main" << std::endl;

    LLi ll;

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
    ll.prepend(1);
    ll.prepend(2);
    ll.prepend(3);
    ll.prepend(4);
    ll.prepend(5);
    ll.prepend(6);

    std::cout << ll.toString() << std::endl;

    Iti it;

    int i = 0;
    for(it = ll.first(); it != ll.end(); ++it)
    {
        std::cout << "ll[" << i++ << "]:\t" << *it <<  std::endl;
    }

    i--;
    for(it = ll.last(); it != ll.end(); --it)
    {
        std::cout << "ll[" << i-- << "]:\t" << *it <<  std::endl;
    }

    return 0;
}
