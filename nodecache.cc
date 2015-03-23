#include "nodecache.h"
#include "node.h"
#include <iostream>

class Node;

NodeCache::NodeCache() : size(0) {
    head = NULL;
}

NodeCache::~NodeCache() {
    purge();
}


void* NodeCache::newNode() {
    if (head != NULL) {
        void * mem = head;
        head = head->next;
        size--;
        std::cerr << "Reusing a node" << std::endl;
        return mem;
    } else {
        // global new
        std::cerr << "Allocating new node" << std::endl;
        return ::new char[sizeof(Node)]; // allocate as char array
    }
}

void NodeCache::recycle(void* mem) {
    std::cerr << "Adding node to cache" << std::endl;
    Node* toRecycle = static_cast<Node*>(mem); // must cast to a Node*, since operator delete takes in a void*
    toRecycle->next = head;
    head = toRecycle;
    size++;
}

void NodeCache::purge() {
    while(head != NULL){
        char* mem = reinterpret_cast<char*>(head); // head was allocated as a char array
        //std::cerr << head->data << std::endl;
        head = head->next;
        ::delete[] mem;
    }
}