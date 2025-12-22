# Week 4 Algorithms

## Lecture Material

- web page: https://cs50.harvard.edu/x/weeks/4/
- notes: https://cs50.harvard.edu/x/notes/4/
- slides: https://cdn.cs50.net/4044/fall/lectures/4/lecture4.pdf
- code: https://cdn.cs50.net/4044/fall/lectures/4/src4/
- Problem Set 4: https://cs50.harvard.edu/x/psets/4/
- topics:
    - Pointers. Segmentation Faults. Dynamic Memory Allocation. Stack. Heap. Buffer Overflow. File I/O. Images.

## Notes

- in C programming language:
    - `&`: gets the memory address of a variable?
    - `*`: prefix it to the name of a variable to make the variable a pointer
    - pointer = variable that stores the (memory) address of something
    - `string` exists as a concept but not as a data type or keyword in C
    - strings are null char `\0` terminated 
    - typedef to create custom data structures or primitive data type alias
    - pointer arithmetic
    - `strcmp()` function
    - `malloc()` function = memory allocation; returns a chunk of memory for a given input size in bytes
        - returns `NULL` if it couldn't find free memory to allocate
        - `NULL` means 0 in memory?
        - `NULL` vs `NUL`?
            - character `0` == `NUL`
            - memory address / pointer `0` == `NULL`
    - `free()` function = returns manually allocated memory back to the computer
    - should code defensively to prevent crashes
    - memory leak
    - Valgrind = CLI tool for reviewing a C program for memory related issues
    - garbage values
    - scope
    - passing by value
    - passing by reference (i.e., addresses)
    - heap overflow
    - stack overflow
    - buffer overflow
    - an array is a buffer of finite size
    - file I/O
        - I/O = Input / Output
    - file I/O functions:
        - fopen
        - fclose
        - fprintf
        - fscanf
        - fread
        - fwrite
        - fseek
        - ...
    - check return values of functions
    - file read / write functions is like playing a video / audio video in YouTube
    - bitmap (BMP)
- in Linux,
    - pipe terminal output to `less` command to paginate or limit the output from another command
        - e.g., `./garbage | less`

## Problem Set 4

- [x] Complete [Volume](https://cs50.harvard.edu/x/psets/4/volume/)'
- [x] Complete 1 of:
    - [ ] [Filter (more)](https://cs50.harvard.edu/x/psets/4/filter/less/)
    - [x] [Filter (less)](https://cs50.harvard.edu/x/psets/4/filter/more/)
- [x] Complete [Recover](https://cs50.harvard.edu/x/psets/4/recover/)
