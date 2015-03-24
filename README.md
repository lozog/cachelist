Cachelist
=================

This is an implementation of a linked list utilizing caching to improve performance.

The idea is that since allocating memory is expensive (time-wise), it makes sense to minimize the number of allocations whenever possible. When a node is deleted from the list, it is put in a "cache". Then, if a new node is inserted, the previously "deleted" node is reused, thus saving the deallocation and reallocation of a node.

This implementation stores integers. At the end of execution, the program outputs the number of nodes that were reused.
Note: The list allows duplicate entries, but search finds the first occurrence.

Commands
=================

* insert [int] - Inserts [int] at the front of the list
* search [int] - Returns the position of [int] in the list, or -1 if <int> is not found
* remove [int] - Removes [int] from the list, no action if <int> not found
* exit: Quits the program
