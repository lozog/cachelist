#ifndef __LIST_H__
#define __LIST_H__
#include <iostream>

class Node;

class List {
    //friend class Node;
    Node* head;
    int sizeOfList;
public:
    List();
    ~List();
    //Node const * getHead() const;

    void insert(int data);
    int search(int data);
    void remove(int data);

    int size();

    friend std::ostream& operator<<(std::ostream &out, const List* list);
};


#endif