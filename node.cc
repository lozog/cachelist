#include "node.h"
#include "nodecache.h"
#include <cassert>
#include <new>

Node::Node(int data, Node* next): data(data), next(next) {}


Node::~Node() {}


int Node::getData() {
    return data;
}

Node* Node::getNext() {
    return next;
}

// custom memory management to facilitate caching

void* Node::operator new (size_t size) {
    assert (size == sizeof(Node));
    return Node::cache.newNode();
}

void Node::operator delete(void* mem) {
    if (mem) {
        Node::cache.recycle(mem);
    }
}

