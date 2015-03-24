#ifndef __NODECACHE_H__
#define __NODECACHE_H__

class Node;

class NodeCache {
    Node* head;
    int size;
    int reusedCount;
public:
    NodeCache();
    ~NodeCache();

    void* newNode();
    void recycle(void* mem);
    void empty();

    int getReusedCount();
};


#endif