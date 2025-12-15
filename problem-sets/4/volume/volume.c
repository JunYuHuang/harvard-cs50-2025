// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;
typedef int16_t WAV_SAMPLE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

const int16_t INT16_T_MAX = 32767;
const int16_t INT16_T_MIN = -32768;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE header[HEADER_SIZE];
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    WAV_SAMPLE sample;
    WAV_SAMPLE scaled_sample;
    while (fread(&sample, sizeof(sample), 1, input) != 0)
    {
        float scaled = sample * factor;
        int clamped = (int) scaled;

        if (clamped > INT16_T_MAX)
            clamped = INT16_T_MAX;
        else if (clamped < INT16_T_MIN)
            clamped = INT16_T_MIN;

        scaled_sample = clamped;

        fwrite(&scaled_sample, sizeof(scaled_sample), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
