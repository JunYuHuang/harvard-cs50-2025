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
    - for each pixel `pixel` (i.e., RGB triple struct in `image`) in the original image,
        - set int `sepiaPixel` to the floor of 1. the sum of sepia products times the original red, green and blue 8-bit int values rounded to the nearest int and 2. 255
        - set `pixel.pixel` to the value at `sepiaPixel`
- `reflect(height, width, image)`:
    - `height`: an int
    - `width`: an int
    - `image`: a 2D array of `RGB` structs of `height` arrays (i.e., rows) of `width` subarrays (i.e., columns)
    - `RGB` struct: of 3 fields that are each an 8-bit int
    - TLDR; horizontally flip the image
    - swap each pixel column / item in each row of the image in-place
    - for each int index `h` from 0 to `height` exclusive,
        - set int index `l` to 0
        - set int index `r` to `width - 1`
        - while `l` < `r`,
            - set BYTE int `temp` = `image[h][l]`
            - set `image[h][l]` = `image[h][r]`
            - set `image[h][r]` = `temp`
            - increment `l` by 1
            - decrement `r` by 1'
- `blur()`: 
    - `height`: an int
    - `width`: an int
    - `image`: a 2D array of `RGB` structs of `height` arrays (i.e., rows) of `width` subarrays (i.e., columns)
    - `RGB` struct: of 3 fields that are each an 8-bit int
    - create a copy `image_copy` of the 2D array `image`
    - for each int index `h` from 0 to `height - 1` inclusive,
        - for each int index `r` from 0 to `width - 1` inclusive,
            - 
    - set `image` to `image_copy`
    - define helper function:
        - `blur_pixel_rgb(rgb, row, col, image)`:
            - create 2D int array `offsets`:
                - has 9 subarrays
                - each subarray is a 2-sized int array containing the `x` (i.e., `row`) and `y` (i.e., `col`) coordinate offsets of a pixel in `image`
                    - subarrays:
                        - `[-1, -1]`, `[0, -1]`, `[1, -1]`, `[-1, 0]`, `[0, 0]`, `[1, 0]`, `[-1, 1]`, `[0, 1]`, `[1, 1]`
            - set int `adj_pixel_count` to 0
            - set int `red_sum` to 0
            - set int `green_sum`to 0
            - set int `blue_sum` to 0
            - for each subarray `offset` in `offsets`,
                - set int `offset_col` = `col` + `offset[0]`
                - set int `offset_row` = `row` + `offset[1]`
                - if `offset_col` is out-of-bounds,
                    - skip to next iteration
                - if `offset_row` is out-of-bounds,
                    - skip to next iteration
                - TODO
                - increment `adj_pixel_count`by 1

## Todos:

- [x] Complete `grayscale()` function
- [x] Complete `sepia()` function
- [x] Complete `reflect()` function
- [ ] Complete `blur()` function