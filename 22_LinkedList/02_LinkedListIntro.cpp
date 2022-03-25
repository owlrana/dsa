/*

    Rather than storing a chunk of memory all at once, we just store new variables as they are recieved.

    Linked List is a collection of nodes in the memory. (memory is not linear and all of them are not at a single place)

    Need to store HEAD and the rest can be found by each others tails.
    Also at times it is beneficial to store the TAIL in case you want to insert (takes O(1) time)

    Feature:
        If a large chunk is not available in the memory, you can just store different nodes in different places and point them
        with each other to create a data structure

*/


