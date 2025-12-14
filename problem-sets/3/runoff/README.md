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
        - Instant Runoff Voting algorithm
            - collect the ranked votes from each ballot / voter,
                - if there is a vote for a candidate by name not on the candidate list,
                    - exit the program
                - if the number of candidates or number of voters is out-of-bounds,
                    - exit the program
            - from the ballots, count the topmost prefererence votes for all candidates
            - if there is a candidate with more than 50% of all votes (i.e., majority vote),
                - declare that candidate as the winner
                - exit the program
            - if all candidates have the same number of votes (i.e., a tie exists),
                - declare all candidates as winners
                - exit the program
            - find the candidate with the min number of votes
                - remove that candidate from the candidate list or pool
                - for any ballots that had the removed candidate as their `n` th preferred candidate,
                    - transfer their eliminated vote to their `n - 1` th preferred candidate that is still in the candidate list
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
        - for each integer index `i` in array `candidates`,
            - if `strcmp(name, candidates[i].name)` returns 0,
                - set integer item at array `references[voter][rank]` to `i`
                - return true
        - return false
    - `tabulate()`:
        - for each `preference` int array in 2D array `preferences`,
            - if `preference[0]` is a valid index in `candidates`,
                - increment `candidates[preference[0]].votes` by 1
    - `print_winner()`:
        - set int `majority_vote_count` = `voter_count` int divided by 2 plus 1
        - for each `candidate` struct item in the `candidates` struct array,
            - if `candidate.votes` is greater or equal to `majority_vote_count`,
                - print `candidate.name`
                - return true
        - return false
    - `find_min()`:
        - set int `min_votes` to `voter_count`
        - for each `candidate` struct item item in array `candidates`,
            - if `candidate.eliminated` is true,
                - skip to the next iteration
            - if `candidates.votes` is less than `min_votes`,
                - set `min_votes` to `candidates.vote`
        - return `min_votes`
    - `is_tie(min)`:
        - set bool `is_tieable` to result of int `voter_count` modulo `candidate_count` is equal to 0
        - if `is_tieable` is false,
            - return false
        - set int `votes_per_candidate_for_tie` to result of `voter_count` divided by `candidate_count`
        - if `min` doesn't equal `votes_per_candidate_for_tie`,
            - return false
        - for each `candidate` struct item in array `candidates`,
            - if `candidate.votes` doesn't equal `votes_per_candidate_for_tie`,
                - return false
        - return true
    - `eliminate(min)`:
        - for each `candidate` struct item at int index `i` in array `candidates`,
            - if `candidate.votes` is less than or equal to `min`,
                - set `candidates.eliminated` = true
                - for each int subarray `preference` in 2D array `preferences`,
                    - if `preference[0]` equals `i`,
                        - shift the remaining the int items in `preference` to the start of `preference` by 1 in-place; like removing the first item in a queue
                            - for int index `i` from 1 to `candidate_count - 1` inclusive,
                                - set `preference[i - 1]` = `preferences[i]`
                            - set `preferences[candidate_count - 1]` = -1
                                - `-1` is a sentinel int value that should be ignored

## Tests:

- [x] An election with any number of candidate (up to the MAX of 9)
- [x] Voting for a candidate by name
- [x] Invalid votes for candidates who are not on the ballot
- [x] Printing the winner of the election if there is only one
- [x] Not eliminating anyone in the case of a tie between all remaining candidates