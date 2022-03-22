/*

    -- QUESTION THAT COMMONLY COMES TO MIND IS WHICH SORTING ALGO TO USE WHEN --

    1.  Insertion Sort - O(n^2) average | O(n) best | O(n^2) worst 
        Preferable when you have an almost sorted array.
        Eg. {1,2,3,5,4,6,7,8,9,5}
        - O(n) complexity in this case (best-case)

    2.  Merge Sort - O(n Log n) every single time (worst, best, average)
        If you want to sort very, super, extremely large arrays (like 100 million)
        Eg. {2,56,23,6,9,99,8,645,4,3,156,8,12,78,76,4,36,6... * 100 million terms}

    3.  Quick Sort - O(n Log n) average | O (n^2) worst
        Best general purpose use case (most popular )
        This is best in mostly all scenarios because its inner loop can be efficiently 
        implemented on most architectures and in most real-world data
        (use Randomized version of quicksort)
        Eg. if the dataset is not really huge and numbers look fairly random, use it \_(*-*)_/

    4.  Bubble Sort - O(n^2) average | O(n) best | O(n^2) worst
        NEVER USE THIS SORTING METHOD. MOST RESEARCH PAPERS SHOW THAT THIS IS WORST DAWG EW.

    5.  Counting Sort and Radix Sort - Linear Time Algo
        If all of your numbers lie in a range from 0 to K.
        Eg. { 0, 6, 3, 2, 1, 7, 5, 8, 9, 10}

    7.  Tim Sort - Is becoming more and more popular year by year

*/