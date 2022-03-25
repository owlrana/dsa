/*
    Pronounced as "Deck", this is a Doubly-Ended Queue.
    You can do both insertion and deletion at both the ends.

    Deck not only allows push/pop from both ends, but also allows RANDOM LOCATION ACCESS through iterators
    This means, it can also behave like an array when you want it to.

    Thus as you can see, DECK IS VERY SIMILAR TO A VECTOR but:
        Deck provides efficient insertion and deletion at both it's front & end.
        Unlike Vectors, Deck are not guaranteed to store elements in CONTIGUOUS memory locations.
        So, Accessing an element by offsetting a pointer may result into undefined behaviour.

    Both vector and deques may be used for mostly same purposes,
    but their under-the-hood workings are VERY different.

    Deques are more complex internally, but as a result do not need to 
    find contiguous space in other memory parts to reallocate elements like vectors.
    As a result, it allows for a much more efficient insertion/deletion especially with very long sequences!!

    For operations that require insertion/deletion between the elements inside deque,
    other than front/end, it will perform worse than lists and forwardlists.

*/

