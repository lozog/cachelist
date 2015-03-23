#include "list.h"
#include "node.h"
#include <iostream>

List::List() {
    head = NULL;
};

List::~List() {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// inserts data at the front of the list
void List::insert(int data){
    Node* newNode = new Node(data, head);
    head = newNode;
    sizeOfList += 1;
}

// returns position in list of data if it exists, -1 if not found.
int List::search(int data) {
    Node* temp = head;
    int pos = 0;
    while ((temp != NULL) && (temp->data != data)){
        //std::cout << temp->data << std::endl;
        pos += 1;
        temp = temp->next;
    }
    if (pos != sizeOfList) return pos;
    else return -1;
}

// removes data from list, if it exists
void List::remove(int data) {
    Node* temp = head;
    if (temp == NULL) {
        // check if list is empty
        return;
    } else {
        if (temp->data == data) {
            // check if first in list is node to remove
            head = head->next;
            delete(temp);
            sizeOfList -= 1;
            return;
        }
        while (temp->next != NULL) {
            // iterate through list
            if (temp->next->data == data) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                temp = temp->next;
                delete(toDelete);
                sizeOfList -= 1;
                return;
            }
            temp = temp->next;
        }
    }
}

// returns size of list
int List::size() {
    return sizeOfList;
}

// External Method Implementations

std::ostream& operator<<(std::ostream &out, const List* list){
    Node* node = list->head;
    out << node->getData();
    while (node->getNext() != NULL){
        out << " ";
        node = node->getNext();
        out << node->getData();
    }
    return out;
}