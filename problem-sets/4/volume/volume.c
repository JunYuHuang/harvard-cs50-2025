// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef uint16_t WAV_SAMPLE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE b;
    while (
        fread(&b, sizeof(b), 1, input) != 0
    )
    {
        if (ftell(input) >= HEADER_SIZE) break;

        fwrite(&b, sizeof(b), 1, output);
    }

    printf(
        "File cursor in input file is at position: %ld\n",
        ftell(input)
    );

    // TODO: Read samples from input file and write updated data to output file
    WAV_SAMPLE sample;
    WAV_SAMPLE scaled_sample;
    while (fread(&sample, sizeof(sample), 1, input) != 0)
    {
        scaled_sample = sample * factor;
        fwrite(&scaled_sample, sizeof(scaled_sample), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
