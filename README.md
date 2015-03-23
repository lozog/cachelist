Cachelist
=================

This is an implementation of a linked list utilizing caching to improve performance.

The idea is that since allocating memory is expensive (time-wise), it makes sense to minimize the number of allocations whenever possible. When a node is deleted from the list, it is put in a "cache". Then, if a new node is inserted, the previously "deleted" node is reused, thus saving the deallocation and reallocation of a node.