#include <iostream>
#include <iomanip>
#include "list.h"
#include "nodecache.h"
#include "node.h"

using std::cout;
using std::endl;
using std::string;

// The Node class has a static member cache
NodeCache Node::cache;

int main() {

    List* list = new List();

    cout << "View the readme for usage info." << endl;

    string command;
    int data;
    while (std::cin >> command) {

        if (command == "insert") {
            if (std::cin >> data) {
                list->insert(data);
            } else {
                cout << "Syntax error: insert expects an int";
            }
        } else if (command == "search") {
            if (std::cin >> data) {
                cout << list->search(data) << endl;
            } else {
                cout << "Syntax error: search expects an int";
            }
        } else if (command == "remove") {
            if (std::cin >> data) {
                list->remove(data);
            } else {
                cout << "Syntax error: remove expects an int";
            }
        } else if (command == "exit") {
            break;
        } else {
            cout << "Syntax error: Recognized commands are insert, search, remove" << endl;
        }

    }

    cout << "Reused " << list->getReusedCount() << " nodes." << endl;
    delete(list);
}