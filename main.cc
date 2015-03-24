#include <iostream>
#include <iomanip>
#include <sstream>
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

    cout << "Commands:" << endl;
    cout << "insert <int>: Inserts <int> at the front of the list" << endl;
    cout << "search <int>: Returns the position of <int> in the list, or -1 if <int> is not found" << endl;
    cout << "remove <int>: Removes <int> from the list, no action if <int> not found" << endl;
    cout << "exit: quits the program" << endl;
    cout << "Note: The list allows duplicate entries, but search finds the first occurrence." << endl;
    
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