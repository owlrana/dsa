/*

    Memory Allocations in C++

    All data is stored in memory. And memory can be allocated in two ways:
        1. Static Allocation (Compile Time)
        2. Dynamic Allocation (Run Time)

    1. Static Allocation
        What is compile time memory allocation?
    --> Eg. in our program we create variables to store data of different types.
        Suppose we make 3 variables in our main function:
            - int x; // 4 bytes
            - char ch; // 1 byte
            - int a[100]; // 400 bytes
        So 4 + 1 + 400 = 405 bytes of memory needs to be allocated during the runtime to run the program

        This amount of memory and the location where they will be stored is fixed during compile time.
        (This memory can be visualised as Virtual Memory)
        Then during runtime, when the actual allocation happens: A mapping is done to virtual memory and
        all the memory is allocated.

        ADVANTAGES OF STATIC ALLOCATION:
            1. Slightly fast than Dynamic Allocation.

        DISADVANTAGES OF STATIC ALLOCATION:
            2. Not flexible. Size cannot grow/shrink during the runtime.

    1. Dynamic Allocation
        What is Dynamic Allocation?
    --> Allows you to define memory requirements during the runtime.
        This dynamic allocation uses special memory called "Heap Memory"
        Heap Memory: The heap is not managed automatically for you and is not as tightly managed by the CPU.
                    It is more like a free-floating region of memory.
                    Heap Memory is a bigger part than Static Memory in Physical Space.
        This memory can also be re-used, by deleting and re-using that space for something else.
        "new" can be used to allocate new memory and "delete" can be used to free.

        THE CHOICE BETWEEN WHEN TO ALLOCATE AND WHEN TO FREE SHOULD BE DONE BY THE PROGRAMMER IN DYNAMIC.

        Eg. new int; // creates integer in the heap part of the memory
                        This gets allocated ONLY when this line of code is run.
                        This statement returns the address and you will have to store this address to use.
            int; // creates a bucket in static part of the memory, it's memory is managed by compiler and
                it's address is FIXED.
        
        But "new int;" does not have a variable then how to store data in it?
        --> This new int allocation happens during runtime and it's address is not fixed.
            You NEED a variable to store the address for this allocation to use it.
            Eg. int *ptr = new int; // stores memory of new allocation and now can be accessed by ptr pointer
                in this, "int *ptr" is in the part of static memory and "new int" is in the heap memory.

        But why waste space with 2 memory allocations instead of using single statically?
        --> This is useful when you want to create a large array to store a lot of data, which can be
            dynamically changed. The starting address will be stored in our pointer variable.

    MEMORY LEAK!!!
        Suppose you did:
            int* pPointer = new int [1000]; // this allocates 4000 new bytes into heap
        later you decide to allocate a char array to the same pointer:
            pPointer = new char[2000]; // this allocates 2000 new bytes into heap
        BUT THE PREVIOUS MEMORY STILL EXISTS!! and worse: You have no ptr to access it so can't delete!!
        This is called memory leak and you should really, really stay away from such leaks. 
        You can not use this memory for the entire runtime of the program. You have wasted this memory!!

        To not do this, first delete your allocation:
            delete [] pPointer; // could have written "delete a" if it didnt point to an array
        This will delete the entire array allocated and then you can allocate new array to it.

*/