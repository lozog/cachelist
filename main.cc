#include <iostream>
#include "list.h"
#include "nodecache.h"
#include "node.h"

// The Node class has a static member cache
NodeCache Node::cache;

int main() {

    List* list = new List();

    // some test values
    list->insert(15);
    list->insert(45);
    list->insert(83);
    list->insert(23487239);
    list->insert(5858);
    std::cout << list << std::endl; // operator<< for list is overloaded
    list->remove(83);
    std::cout << list << std::endl;
    list->insert(500);
    std::cout << list << std::endl;


    delete(list);
}