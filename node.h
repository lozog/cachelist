#ifndef __NODE_H__
#define __NODE_H__
#include <iostream>

class NodeCache;

class Node {
    //allow List and NodeCache to access Node private fields
    friend class List;
    friend class NodeCache;

    static NodeCache cache;

    int data;
    Node* next;
public:
    Node(int data, Node* next);
    ~Node();

    void* operator new (size_t size);
    void operator delete (void* mem);

    int getData();
    Node* getNext();

    int getReusedCount();

};



#endif