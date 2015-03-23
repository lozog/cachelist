#include "node.h"
#include "nodecache.h"
#include <cassert>
#include <new>

Node::Node(int data, Node* next): data(data), next(next) {}


Node::~Node() {
    #if 0
    if (next != NULL)

    delete(next);
#endif
}


int Node::getData() {
    return data;
}

Node* Node::getNext() {
    return next;
}

void* Node::operator new (size_t size) {
    assert (size == sizeof(Node));
    return Node::cache.newNode();
}

void Node::operator delete(void* mem) {
    if (mem) {
        Node::cache.recycle(mem);
    }
}

