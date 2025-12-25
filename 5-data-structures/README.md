# Week 5 Data Structures

## Lecture Material

- web page: https://cs50.harvard.edu/x/weeks/5/
- notes: https://cs50.harvard.edu/x/notes/5/
- slides: https://cdn.cs50.net/5055/fall/lectures/5/lecture5.pdf
- code: https://cdn.cs50.net/5055/fall/lectures/5/src5/
- Problem Set 5: https://cs50.harvard.edu/x/psets/5/
- topics:
    - Abstract Data Types. Queues, Stacks. Linked Lists. Trees, Binary Search Trees. Hash Tables. Tries.

## Notes

- data structures
- queues
    - FIFO: First In First Out
    - functions:
        - enqueue
        - dequeue
- stacks
    - LIFO: Last In First Out
    - functions:
        - push
        - pop
- resizing arrays
- linked lists
    - example C code:
        ```c
        typedef struct node
        {
            int number;
            struct node *next;
        } node;
        ```
- corner cases
- trees
- binary search tree
- dictionaries
- hash functions
- bucketize
- hash table = array + linked list
- collisions
- trie:
    - abbrev. for "retrieval"
    - tree of arrays
- in C programming language:
    - `struct`
    - `.`
    - `*`
    - `->`:
    - should be freeing memory to prevent memory leaks

## Problem Set 5

- [x] Complete [Inheritance](https://cs50.harvard.edu/x/psets/5/inheritance/)
- [ ] Complete [Speller](https://cs50.harvard.edu/x/psets/5/speller/)
