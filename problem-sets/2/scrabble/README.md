# Scrabble

## General Notes

- PEDAC: Problem
    - inputs:
        - `player_1_word`: a string entered by player 1
        - `player_2_word`: a string entered by player 2
    - outputs:
        - none
    - side effects / mutations:
        - prints `Player 1 wins!` if `player_1_word`'s value is larger than `player_2_word`'s value
        - prints `Player 2 wins!` if `player_2_word`'s value is larger than `player_1_word`'s value
        - prints `Tie!` if `player_1_word`'s value is the same as `player_2_word`'s value
    - constraints / rules:
        - each word's numerical value is the sum of each numerical valu of all its characters
        - only uppercase alphabetical chars have arbitrary numerical values:
            - `A` = 1
            - `B` = 3
            - `C` = 3
            - `D` = 2
            - `E` = 1
            - `F` = 4
            - `G` = 2
            - `H` = 4
            - `I` = 1
            - `J` = 8
            - `K` = 5
            - `L` = 1
            - `M` = 3
            - `N` = 1
            - `O` = 1
            - `P` = 3
            - `Q` = 10
            - `R` = 1
            - `S` = 1
            - `T` = 1
            - `U` = 1
            - `V` = 4
            - `W` = 4
            - `X` = 8
            - `Y` = 4
            - `Z` = 10
        - chars that are not uppercase alphabetical chars have value 0
    - ASCII int values to chars:
        - `A` = 65
        - `B` = 66
        - ...
        - `Z` = 90
        - ...
        - `a` = 97
        - `b` = 98
        - ...
        - `z` = 122
        - use offset (`char` - 65 ) for storing ASCII int values of uppercase chars in the array / map
- PEDAC: Examples
    - skipped

## Solution 1

- array to map ASCII value of an alphabetical char to the arbitrary int value
