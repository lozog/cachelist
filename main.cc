#include <iostream>
#include "list.h"
#include "nodecache.h"
#include "node.h"


NodeCache Node::cache;

int main() {

    List* list = new List();
    list->insert(15);
    list->insert(45);
    list->insert(83);
    list->insert(23487239);
    list->insert(5858);
    std::cout << list << std::endl;
    list->remove(83);
    std::cout << list << std::endl;
    list->insert(500);
    std::cout << list << std::endl;
    delete(list);
}