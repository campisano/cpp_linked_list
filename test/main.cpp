#include <iostream>
#include <linked_list.hpp>

int main() {
    std::cout << "main" << std::endl;

    containers::LinkedList ll;

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
    ll.append(1);
    ll.append(2);
    ll.append(3);
    ll.append(4);
    ll.append(5);
    ll.append(6);

    std::cout << ll.toString() << std::endl;

    containers::It it;

    int i = 0;
    for(it = ll.start(); it != ll.end(); ++it)
    {
        std::cout << i++ << ": " << *it <<  std::endl;
    }

    return 0;
}
