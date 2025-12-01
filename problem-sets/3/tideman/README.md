# Tideman

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
    - misc:
        - Tideman voting mechanics:
            - create `n!` pairs / victories for `n` candidates
            - for each vote `v`,
                - `v` includes a distinct vote for every candidate exactly once
            - e.g., 8 kids prefer cookies over chips,
                - -> winning margin of cookies over chips = 8
            - sort pairs / victories in descending order (largest winning margins to smallest)
            - connect winners to losers in a uni-directed graph
                - arrows join a winner to a loser
                    - arrow points to loser
                    - arrow origin points to winner
                - start with largest victory firstg
                - skip connecting nodes that would create a loop
            - return the node / pair / victory that has no arrows pointing (in)to it
- PEDAC: Examples
    - case 1: 3 candidates, 11 voters
        - candidates:
            - Co: Cookies
            - Ch: Chips
            - Ic: Ice Cream
        - all pairs for `n` = candidates count
            - n! = 3! = 3 * 2 * 1 = 6
        - a

## Solution 1: brute force

- a