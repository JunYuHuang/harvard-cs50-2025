# Recover

## General Notes

- PEDAC: Problem
    - inputs:
        - `memory_card`: a memory card that stores JPEG images in a .RAW format
    - outputs:
        - `images`: 1+ `.jpeg` format images extracted from `memory_card` that are named in a numbering scheme from starting at `000`
    - side effects / mutations:
        - none
    - constraints / rules:
        - a `JPEG` image file
            - header / signature:
                - byte 1 = 0xff
                - byte 2 = 0xd8
                - byte 3 = 0xff
                - next 4 bits = 0xe
            - ends before the next JPEG signature
            - may have zeroes or slack space in the image
        - `memory_card`: a file that stores `JPEG` images in the FAT file system
        - FAT file system
            - has block size 512 Bytes (B)
            - block size = container size of data stored in the FAT file system
            - means any file whose size is < 512 Bytes still takes up 512 Bytes
            - any file > 512 bytes takes up multiple 512 Byte blocks
        - for a `JPEG` file in a FAT file system file,
            - it is guaranteed to start at the start of any 512 Byte block
            - may end somewhere after the JPEG signature / header to the end of a block
- PEDAC: Examples
    - skipped

## Solution 1: brute force

- if `argc` != 2,
    - print error message
    - return 1
- if can't open the forsenic image memory card `memory_card`,
    - print error message
    - return 1
- set int `jpeg_counter` to 0
- open the file `memory_card`
- while not at end of file, read `memory_card` in 512 byte blocks,
    - if `is_jpeg_signature()`
        - create a new image file
        - `jpeg_counter++`
- close the input memory card file
- helper functions
    - `is_jpeg_signature(file_buffer)`:
        - if first 4 bytes of the variable length array `file_buffer` matches the byte values of a JPEG signature,
            - return true
        - return false