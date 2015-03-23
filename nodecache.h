#ifndef __NODECACHE_H__
#define __NODECACHE_H__

class Node;

class NodeCache {
    Node* head;
    int size;
public:
    NodeCache();
    ~NodeCache();

    void* newNode();
    void recycle(void* mem);
    void purge();
};


#endif