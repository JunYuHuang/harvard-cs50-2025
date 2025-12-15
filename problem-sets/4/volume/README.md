# Volume

## General Notes

- PEDAC: Problem
    - inputs:
        - `input`: an audio file in the `.wav` format
        - `factor`: a float that represents the multiplier number for scaling the volume in `input` up or down
    - outputs:
        - `output`: a new `.wav` output file created from `input` and `factor`
    - side effects / mutations:
        - none
    - constraints / rules:
        - `input` must be a file that has the `.wav` file format / extension / suffix
        - an `output` `.wav` file created from a `factor`of 2.0 should be twice as loud as the original `input` `.wav` file
        - an `output` `.wav` file created from a `factor`of 0.5 should be half as loud as the original `input` `.wav` file
    - misc:
        - `.wav` file format anatomy = header + body
            - header = first 44 bytes
            - body = from the 45th byte to the end of the file
                - an ordered list of 2-byte (i.e., 16-bit) signed (i.e., can be negative, 0, or positive) integers
                    - each int represents a timestamped audio signal
- PEDAC: Examples
    - skipped

## Solution 1: brute force

- get the 4 command-line arguments from the user at these indices:
    - `argv[0]`: name of this compiled program i.e., `./volume`
    - `argv[1]`: name of the input file e.g., `input.wav`
    - `argv[2]`: name of the output file to create e.g., `output.wav`
    - `argv[3]`: scaling `factor` float
- set the FILE pointer `*input` to the opened the input file `input.wav`
- while the file cursor reading the file pointed by `*input` 1 byte at a time,
    - if the file cursor or pointer is not at the 45th byte,
        - copy that byte to the output file pointed to by FILE pointer `*output`
    - else,
        - set 16-bit integer `sample` to the integer represented by the current and the next byte
        - set 16-bit integer `scaled_sample` = `sample` * `factor`
        - copy the bytes represented by `scaled_sample` to the next 2 bytes in the file pointed by `*output
