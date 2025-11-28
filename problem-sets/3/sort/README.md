# Sort

## General Notes

- PEDAC: Problem
    - inputs:
        - `random5000`: a text file with 5000 positive integers each separated by a newline char in an unsorted order
        - `random10000`: a text file with 10000 positive integers each separated by a newline char in an unsorted order
        - `random50000`: a text file with 50000 positive integers each separated by a newline char in an unsorted order
        - `sorted5000`: a text file with 5000 positive integers each separated by a newline char in ascending sorted order
        - `sorted10000`: a text file with 10000 positive integers each separated by a newline char in ascending sorted order
        - `sorted50000`: a text file with 50000 positive integers each separated by a newline char in ascending sorted order
        - `reversed5000`: a text file with 5000 positive integers each separated by a newline char in a reversed order
        - `reversed10000`: a text file with 10000 positive integers each separated by a newline char in a reversed order
        - `reversed50000`: a text file with 50000 positive integers each separated by a newline char in a reversed order
    - outputs:
        - ?
    - side effects / mutations:
        - ?
    - constraints / rules:
        - determine which compiled `sort*` program corresponds to which of the 3 sorting algorithms
        - a
    - misc:
        - `sort1`: a compiled C program that implements selection, bubble, or merge sort
        - `sort2`: a compiled C program that implements selection, bubble, or merge sort
        - `sort3`: a compiled C program that implements selection, bubble, or merge sort
    - theories:
        - by benchmark time, algorithms in descending runtime (fastest to slowest) should be:
            - merge sort
            - selection sort
            - bubble sort
    - bubble sort:
        - pseudocode algorithm:
            - set `numbers` to a non-zero lengthed integer array
            - set integer `n` to length of integer array
            - repeat `n` times,
                - for integer `i` from `0` to `n - 2`,
                    - if `number[i]` and `numbers[i + 1]` are out of order,
                        - swap them
                    - if no swaps,
                        - quit
        - runtime complexity:
            - worst case:
                - = (n - 1) * (n - 1)
                - = n^2 - 1n - 1n + 1
                - = n^2 - 2n + 1
                - = O(n^2)
            - best case: O(n)
    - merge sort:
        - pseudocode algorithm:
            - if only one number,
                - quit
            - else
                - sort left half of numbers
                - sort right half of numbers
                - merge sorted halves
        - runtime complexity:
            - worst case: O(n * log2(n))
            - best case: O(n * log2(n))
    - selection sort:
        - pseudocode algorithm:
            - set `numbers` to a non-zero lengthed integer array
            - set integer `n` to length of integer array
            - for integer `i` from 0 to `n` - 1,
                - find smallest number between `numbers[i]` and `number[n-1]`
                - swap smallest number with `number[i]`
        - runtime complexity:
            - worst case:
                - = (n - 1) + (n - 2) + (n - 3) + ... + 1
                - = n (n - 1) / 2
                - = (n^2 - n ) / 2
                - = n^2 / 2 - n / 2
                - = O(n^2)
            - best case:
                - O(n^2)
- PEDAC: Examples
    - skipped

## Solution 1: check benchmark results

- running the 3 sort programs against the random input texts:

```
=====> speed ranking for `random5000.txt` (looking at time for `real`):
1. `sort2`
2. `sort3`
3. `sort1`

===> `time ./sort1 random5000.txt`:
...
real    0m0.024s
user    0m0.016s
sys     0m0.003s

===> `time ./sort2 random5000.txt`:
...
real    0m0.010s
user    0m0.000s
sys     0m0.007s

===> `time ./sort3 random5000.txt`:
...
real    0m0.019s
user    0m0.011s
sys     0m0.004s

=====> speed ranking for `random10000.txt` (looking at time for `real`):
1. `sort2`
2. `sort3`
3. `sort1`

===> `time ./sort1 random10000.txt`:
...
real    0m0.075s
user    0m0.058s
sys     0m0.008s

===> `time ./sort2 random10000.txt`:
...
real    0m0.019s
user    0m0.003s
sys     0m0.010s

===> `time ./sort3 random10000.txt`:
...
real    0m0.046s
user    0m0.035s
sys     0m0.004s

=====> speed ranking for `random50000.txt` (looking at time for `real`):
1. `sort2`
2. `sort3`
3. `sort1`

===> `time ./sort1 random50000.txt`:
...
real    0m1.939s

===> `time ./sort2 random50000.txt`:
...
real    0m0.072s

===> `time ./sort3 random50000.txt`:
...
real    0m0.869s

=====> speed ranking for `sorted5000.txt` (looking at time for `real`):
1. `sort2`
2. `sort3`
3. `sort1`

===> `time ./sort1 sorted5000.txt`:
...
real    0m0.018s

===> `time ./sort2 sorted5000.txt`:
...
real    0m0.009s

===> `time ./sort3 sorted5000.txt`:
...
real    0m0.016s

=====> speed ranking for `sorted10000.txt` (looking at time for `real`):
1. `sort2`
2. `sort1`
3. `sort3`

===> `time ./sort1 sorted10000.txt`:
...
real    0m0.016s

===> `time ./sort2 sorted10000.txt`:
...
real    0m0.014s

===> `time ./sort3 sorted10000.txt`:
...
real    0m0.047s

=====> speed ranking for `sorted50000.txt` (looking at time for `real`):
1. `sort2`
2. `sort1`
3. `sort3`

===> `time ./sort1 sorted50000.txt`:
...
real    0m0.064s

===> `time ./sort2 sorted50000.txt`:
...
real    0m0.061s

===> `time ./sort3 sorted50000.txt`:
...
real    0m0.864s

=====> speed ranking for `reversed5000.txt` (looking at time for `real`):
1. `sort2`
2. `sort3`
3. `sort1`

===> `time ./sort1 reversed5000.txt`:
...
real    0m0.039s

===> `time ./sort2 reversed5000.txt`:
...
real    0m0.014s

===> `time ./sort3 reversed5000.txt`:
...
real    0m0.023s

=====> speed ranking for `reversed5000.txt` (looking at time for `real`):
1. `sort2`
2. `sort3`,
3. `sort1`

===> `time ./sort1 reversed50000.txt`:
...
real    0m1.903s

===> `time ./sort2 reversed50000.txt`:
...
real    0m0.059s

===> `time ./sort3 reversed50000.txt`:
...
real    0m0.853s
```

