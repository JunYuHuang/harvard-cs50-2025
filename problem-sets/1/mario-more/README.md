# Mario (more)

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
    - case 1:
        - inputs: `height` = 1
        - side-effect / print out:
            ```
            Height: 1
            #  #
            ```
    - case 2:
        - inputs: `height` = 2
        - side-effect / print out:
            ```
            Height: 2
             #  # 
            ##  ##
            ```

## Solution 1

- `height`: uninitialized integer variable
- prompt user for `height` input value
- while `height` is less than 1 or greater than 8,
    - prompt user for `height` input value
- print out pyramids with given height
- functions:
    - `bool is_valid_height(int height)`:
        - if `height` is an integer in the range \[1, 8] inclusive,
            - return true
        - return false
    - `void print_pyramids(int height)`:
        - prints the 2 pyramids with the 2-space char gap row by row
        - loop for int `row` from 0 to `height` exclusive,
            - print the current row for the left pyramid:
                - loop for int `l_pyramid_col` from 0 to `height` exclusive,
                    - set int variable `l_pyramid_hash_count` to `l_pyramid_col` plus 1
                    - set int variable `l_pyramid_space_count` to `height` minus `l_pyramid_hash_count`
                    - print space ` ` char `l_pyramid_space_count` times
                    - print hash `#` char `l_pyramid_hash_count` times
            - print the 2 space or empty ` ` chars
            - print the current row for the right pyramid:
                - loop for int `r_pyramid_col` from 0 to `height` exclusive,
                    - set int variable `r_pyramid_hash_count` to `r_pyramid_col` plus 1
                    - set int variable `r_pyramid_space_count` to `height` minus `r_pyramid_hash_count`
                    - print hash `#` char `r_pyramid_hash_count` times
                    - print space ` ` char `r_pyramid_space_count` times
            - print a newline char
    - `void print_l_pyramid_row(row, height)`:
        - prints the current row of the left pyramid to the terminal output
    - `void print_r_pyramid_row(row, height)`:
        - prints the current row of the right pyramid to the terminal output