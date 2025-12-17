#include "helpers.h"
#include <math.h>

// Function prototypes
BYTE sepia_pixel(
    BYTE red, BYTE green, BYTE blue,
    float redMultiplier, float greenMultiplier, float blueMultiplier
);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            BYTE rgb_average = (BYTE) round((
                image[h][w].rgbtBlue +
                image[h][w].rgbtGreen +
                image[h][w].rgbtRed
            ) / 3.0);
            image[h][w].rgbtBlue = rgb_average;
            image[h][w].rgbtGreen = rgb_average;
            image[h][w].rgbtRed = rgb_average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            BYTE new_red = sepia_pixel(
                image[h][w].rgbtRed,
                image[h][w].rgbtGreen,
                image[h][w].rgbtBlue,
                .393, .769, .189
            );
            BYTE new_green = sepia_pixel(
                image[h][w].rgbtRed,
                image[h][w].rgbtGreen,
                image[h][w].rgbtBlue,
                .349, .686, .168
            );
            BYTE new_blue = sepia_pixel(
                image[h][w].rgbtRed,
                image[h][w].rgbtGreen,
                image[h][w].rgbtBlue,
                .272, .534, .131
            );
            image[h][w].rgbtRed = new_red;
            image[h][w].rgbtGreen = new_green;
            image[h][w].rgbtBlue = new_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        int l = 0;
        int r = width - 1;
        while (l < r)
        {
            RGBTRIPLE temp = image[h][l];
            image[h][l] = image[h][r];
            image[h][r] = temp;
            l++;
            r--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// sepia helper function
BYTE sepia_pixel(
    BYTE red, BYTE green, BYTE blue,
    float redMultiplier, float greenMultiplier, float blueMultiplier
)
{
    int result = round(
        redMultiplier * red +
        greenMultiplier * green +
        blueMultiplier * blue
    );

    if (result < 0) return 0;
    if (result > 255) return 255;
    return (BYTE) result;
}