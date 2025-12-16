# Filter (Less)

## General Notes

- PEDAC: Problem
    - inputs:
        - a
    - outputs:
        - a
    - side effects / mutations:
        - none
    - constraints / rules:
        - a
- PEDAC: Examples
    - skipped

## Solution 1: brute force

- `grayscale(height, width, image)`:
    - `height`: an int
    - `width`: an int
    - `image`: a 2D array of `RGB` structs of `height` arrays (i.e., rows) of `width` subarrays (i.e., columns)
    - `RGB` struct: of 3 fields that are each an 8-bit int
    - for each pixel `pixel` (i.e., RGB triple struct in `image`) in the original image,
        - set int `average_RGB_value` to the average of the 3 8-bit integers in `pixel`
        - set all 3 8-bit integers in `pixel` to the value `average_RGB_value`
- `sepia(height, width, image)`:
    - `height`: an int
    - `width`: an int
    - `image`: a 2D array of `RGB` structs of `height` arrays (i.e., rows) of `width` subarrays (i.e., columns)
    - `RGB` struct: of 3 fields that are each an 8-bit int
    - todo