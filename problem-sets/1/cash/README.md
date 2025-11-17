# Cash

## General Notes

- PEDAC: Problem
    - inputs:
        - `height`: positive integer in the range \[1, 8]
    - outputs:
        - none
    - side effects / mutations:
        - prints the given height of the pyramids like this:
            - `Height: {pyramid height}`
        - prints 2 pyramids separated by 2 space ` ` chars wide no matter the height of the pyramids
            - each printed row = left pyramid + gap + right pyramid
                - is of length `height` * 2 + 2 chars long
        - 2 pyramids are always the same height
        - for each pyramid,
            -  top of each pyramid has a single hash `#` char
            - bottom of each pyramid is `height` hash `#` chars wide
            - from the top-most to the bottom-most row, each descending row or layer has an additional hash `#` char
            - it has `height` rows or that many characters tall
            - each row has `height` characters, whether they are empty space ` ` or hash `#` chars
        - left pyramid is right-aligned;
        - right pyramid is left-aligned;
    - constraints:
        - program keeps prompting for `height` until the input is a positive integer in the range \[1, 8] inclusive
- PEDAC: Examples
    - t

## Solution 1

- todo