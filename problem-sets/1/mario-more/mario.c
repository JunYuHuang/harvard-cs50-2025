#include <stdio.h>
#include <cs50.h>

bool is_invalid_height(int height);
void print_pyramids(int height);
void print_l_pyramid_row(int row, int height);
void print_r_pyramid_row(int row, int height);

int main(void)
{
    int height;

    while (is_invalid_height(height))
    {
        height = get_int("Height: ");
    }

    print_pyramids(height);
}

bool is_invalid_height(int height)
{
    if (height < 1 || height > 8) return true;
    return false;
}

void print_pyramids(int height)
{
    for (int row = 0; row < height; row++)
    {
        print_l_pyramid_row(row, height);
        printf("  ");
        print_r_pyramid_row(row, height);
        printf("\n");
    }
}

void print_l_pyramid_row(int row, int height)
{
    int pyramid_hash_count = row + 1;
    int pyramid_space_count = height - pyramid_hash_count;
    
    while (pyramid_space_count > 0)
    {
        printf(" ");
        pyramid_space_count--;
    }

    while (pyramid_hash_count > 0)
    {
        printf("#");
        pyramid_hash_count--;
    }
}

void print_r_pyramid_row(int row, int height)
{
    int pyramid_hash_count = row + 1;
    int pyramid_space_count = height - pyramid_hash_count;
    
    while (pyramid_hash_count > 0)
    {
        printf("#");
        pyramid_hash_count--;
    }

    while (pyramid_space_count > 0)
    {
        printf(" ");
        pyramid_space_count--;
    }
}