# Runoff

## General Notes

- PEDAC: Problem
    - inputs:
        - a
    - outputs:
        - none
    - side effects / mutations:
        - a
    - constraints / rules:
        - a
- PEDAC: Examples
    - skipped

## Solution 1: brute force

- helper functions:
    - `vote(voter, rank, name)`:
        - if vote is valid, updates `candidates` array and returns true
        - else, returns false
        - if int `voter` index is out of bounds,
            - return false
        - if int `voter` index is out of bounds,
            - return false
        - if string `name` doesn't match a `name` field value of a struct item in array `candidates`,
            - return false
        - update `candidates` array
        - return true
    - `tabulate()`:
        - return nothing; is of return type `void`
        - todo

## Tests:

- [ ] An election with any number of candidate (up to the MAX of 9)
- [ ] Voting for a candidate by name
- [ ] Invalid votes for candidates who are not on the ballot
- [ ] Printing the winner of the election if there is only one
- [ ] Not eliminating anyone in the case of a tie between all remaining candidates