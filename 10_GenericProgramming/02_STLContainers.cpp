/*
    -- CONTAINERS IN STL --
    
    1.  Sequence Containers: implement data structures which can be accessed in a sequential manner
            - vector (dynamic array)
            - list (this is a doubly linked list)
            - deque ("deck", double ended queue and NOT dequeue)
            - arrays (normal array)
            - forward_list (this is a singly linked list)

    2.  Container Adapters: provide a different interface for Sequential Containers
            - queue: (queue can be implemented using vector, array, but is FIFO like a line of ATM)
            - priority queue: (heap data structure but each element is given priorities)
            - stack: (has ordered elements but gives access to only the top element)

    3.  Associative Containers: implement sorted data structures that can be quickly searched (O(logn) complexity)
            - set: (data will always be in a sorted order like a sorted array)
            - multiset: (like sets, but allows multiple instances of the same object)
            - map: (fast and ordered key-lookup data structure, are not sorted but are speedily accessible)
            - multimap: (similar to map, but instead MULTIPLE ELEMENTS CAN HAVE THE SAME KEY)

    4.  Unordered Associative Containers: implement unordered data structures that can be quickly searched 
            - unordered set
            - unordered multiset 
            - unordered map
            - unordered multimap  

    -- ALL OF THESE CONTAINERS ARE GENERIC AND YOU CAN USE THEM TO STORE ANY DATATYPE --
*/