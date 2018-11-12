#include <iostream>
#include <linked_list.hpp>

int main() {
    std::cout << "main" << std::endl;

    containers::LinkedList<int> ll;

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

    containers::It<int> it;

    int i = 0;
    for(it = ll.first(); it != ll.end(); ++it)
    {
        std::cout << i++ << ": " << *it <<  std::endl;
    }

    return 0;
}
