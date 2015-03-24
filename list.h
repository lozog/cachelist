#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>

class Node;

class List {
    Node* head;
    int sizeOfList;
public:
    List();
    ~List();

    void insert(int data);
    int search(int data);
    void remove(int data);

    int size();

    int getReusedCount();

    friend std::ostream& operator<<(std::ostream &out, const List* list);
};


#endif