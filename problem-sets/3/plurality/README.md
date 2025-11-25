# Plurality

## General Notes

- PEDAC: Problem
    - inputs:
        - `candidates`: a string array
            - of size in the range \[1, 9] inclusive
        - `voted_candidates`: a string array
            - of the same size as `candidates`
    - outputs:
        - none
    - side effects / mutations:
        - prints total count of voters i.e., `Number of voters: <total votes count>`
        - prints name of candidate(s) that has the most votes
            - may print 1+ names if winning candidates have the same number of rules
        - prints error message to prompt for at least 1? candidate if run without command-line arguments
    - constraints / rules
        - invalid votes still count against the total vote count
            - invalid vote = vode for a someone not part of the `candidates` string array
        - must vote 
- PEDAC: Examples
    - skipped

## Solution 1: brute force

- helper functions
    - `vote(name)`:
        - if array `candidates`of type struct `candidate` has a struct whose `name` string field has the string value `name`,
            - increment that `candidates[i]`'s `votes` integer field by 1
            - return true
        - return false
    - `print_winner(void)`:
        - todo
- if run with less than 1 command-line argument,
    - print message `Usage: plurality [candidate ...]`
    - exit with `1`
- set integer `candidates_count` to `argc - 1`
- for integer `i` from 1 to int `candidates_count` exclusive,
    - set integer `j` to `i - 1`
    - set `candidates[i].name` to `argv[j]`
    - set `candidates[i].votes` to integer `0`
- print `Number of voters: <candidates_count>`
- set integer `max_votes` to 0
- for integer `i` from 0 to `candidates_count` exclusive,
    - set string `votee` to user input for the to-be-voted candidate's name `Vote: `
    - for each string `candidate` in string array `candidates`,
        - if `candidate` has the same string value as `votee`,
            - increment `candidate` struct's `votes` value by 1
            - if `candidate.votes` > `max_votes`,
                - set `max_votes` to `candidate.votes`
            - print a newline char
            - continue to next iteration
    - print `Invalid vote.`
- for integer `i` from 0 to `candidates_count` exclusive,
    - if `candidates[i].votes` == `max_votes`,
        - print `candidates[i].name`
- return 0
