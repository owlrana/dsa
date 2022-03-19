/*
    -- ITERATORS -- 
    Iterators is an entity that helps us to access the data within containers with certain restrictions

    1.  Input Iterators:
        An entity through which you can read data into the container and then move ahead.
        Eg. A keyboard

    2.  Output Iterators:
        An entity thruogh which you can write data into the container and move ahead.

    3.  Forward Iterators:
        Iterator with the functionalities of input and output iterators but in a single direction.
        Eg. Singly Linked List

    4.  Bidirectional Iterators:
        Forward iterator that can move in both directions.

    5.  Random Access Iterators:
        Iterator that can read/write in both directions and can also take jumps between values.

    -- WHY DO WE EVEN NEED ITERATORS? --
    Like we created a function earlier, that was independent of the type of arguments it accepted...
    we also want to make algorithms that are independent of the underlying data structures.
    Example-
        We made a search() function that accepts arguments of all datatypes' arrays using TEMPLATES.
        Now we can make search() function to work on all containers (not just arrays) using ITERATORS.
*/