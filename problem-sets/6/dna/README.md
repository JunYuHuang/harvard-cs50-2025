# DNA

## General Notes

- PEDAC: Problem 
    - inputs:
        - `database.csv`: `.csv` file of table headers `name` and `x` number of unique STRs (Short Tandem Repeats)
        - `sample.txt`: `.txt` file of a single line or string of unbroken DNA sample chars (`A, T, G, C`)
    - outputs:
        - none
    - side effects / mutations:
        - if `sample.txt` matches a row in `database.csv`,
            - print the matching row in `database.csv`'s `name` column string value
        - else,
            - print string `No match`
    - constraints / rules:
        - a
- PEDAC: Examples
    - skipped

## Solution 1: brute force

- if program is run without 3 CLI arguments,
    - print error message like `Usage: python dna.py database.csv sample.txt`
    - exit program with status code `1`
- open `database.csv`
    - read it into the hashmap `str_tuples_to_names`
        - hashmap keys: int tuples of each record's unique STR counts
        - hashmap values: string value of each record's name value
        - use hashmap that maps int tuples of the counts of each STRs to the string name of the person who DNA matches those STR counts
    - store each CSV value of the first record / line except first value `name` in the string array `strs`
- open and read the contents of `sample.txt` into the string variable `sample`
- set `sample_str_counts` to an empty int array
- loop for each string `str` in `strs` array
    - append to `sample_str_counts` the integer value returned from calling `longest_match(sample, str)`
- set `sample_str_counts` to itself converted to a tuple
- if `sample_str_counts` is a key in hashmap `str_tuples_to_names`,
    - print the string value of that key
- else,
    - print `No match`

## Tests

- [x] `python dna.py databases/small.csv sequences/1.txt` -> `Bob`
- [x] `python dna.py databases/small.csv sequences/2.txt` -> `No match`
- [x] `python dna.py databases/small.csv sequences/3.txt` -> `No match`
- [x] `python dna.py databases/small.csv sequences/4.txt` -> `Alice`
- [x] `python dna.py databases/large.csv sequences/5.txt` -> `Lavender`
- [x] `python dna.py databases/large.csv sequences/6.txt` -> `Luna`
- ...
- [x] `python dna.py databases/large.csv sequences/19.txt` -> `Fred`
