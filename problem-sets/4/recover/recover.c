#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

bool is_jpeg_signature(uint8_t buffer[]);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open file '%s'\n", argv[1]);
        return 1;
    }

    int jpeg_count = 0;
    char jpeg_name[9];
    uint8_t buffer[BLOCK_SIZE];
    FILE *output = NULL;

    while (fread(buffer, sizeof(buffer), 1, input) != 0)
    {
        if (is_jpeg_signature(buffer))
        {
            if (output != NULL)
            {
                fclose(output);
            }

            sprintf(jpeg_name, "%03d.jpeg", jpeg_count);
            output = fopen(jpeg_name, "wb");
            if (output == NULL)
            {
                printf("Could not open file '%s'\n", jpeg_name);
                return 1; 
            }
            jpeg_count++;
        }

        if (output != NULL)
        {
            fwrite(buffer, sizeof(buffer), 1, output);
        }
    }

    fclose(input);
    if (output != NULL)
    {
        fclose(output);
    }
}

bool is_jpeg_signature(uint8_t buffer[])
{
    if (buffer[0] != 0xff) return false;
    if (buffer[1] != 0xd8) return false;
    if (buffer[2] != 0xff) return false;
    return (buffer[3] >= 0xe0 && buffer[3] <= 0xef);
}