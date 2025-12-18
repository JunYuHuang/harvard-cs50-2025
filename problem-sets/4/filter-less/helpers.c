#include "helpers.h"
#include <math.h>

// Constants

// Each int subarray represents all coordinates surrounding a pixel point
// `(x, y)` on a cartesian place including the point itself
const int OFFSETS[9][2] = {
    {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0, 0},
    {1, 0}, {-1, 1}, {0, 1}, {1, 1}
};

// Function prototypes
BYTE sepia_pixel(
    BYTE red, BYTE green, BYTE blue,
    float redMultiplier, float greenMultiplier, float blueMultiplier
);

RGBTRIPLE blur_pixel_rgb(
    int height, int width, int max_height, int max_width, 
    RGBTRIPLE image[max_height][max_width]
);

BYTE clamp_pixel(int rgb);

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
    // copy `image`
    RGBTRIPLE image_copy[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image_copy[h][w] = image[h][w];
        }
    }

    // mutate `image` in-place
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w] = blur_pixel_rgb(
                h, w, height, width, image_copy
            );
        }
    }

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

// blur helper function
RGBTRIPLE blur_pixel_rgb(
    int height, int width, int max_height, int max_width, 
    RGBTRIPLE image[max_height][max_width]
)
{
    float adj_pixel_count = 0;
    int red_sum = 0;
    int green_sum = 0;
    int blue_sum = 0;
    
    for (int i = 0; i < 9; i++)
    {
        int adj_width = width + OFFSETS[i][0];
        int adj_height = height + OFFSETS[i][1];

        if (adj_width < 0 || adj_width >= max_width) continue;
        if (adj_height < 0 || adj_height >= max_height) continue;

        red_sum += image[adj_height][adj_width].rgbtRed;
        green_sum += image[adj_height][adj_width].rgbtGreen;
        blue_sum += image[adj_height][adj_width].rgbtBlue;
        adj_pixel_count += 1;
    }

    RGBTRIPLE pixel;
    pixel.rgbtRed = clamp_pixel(round(red_sum / adj_pixel_count));
    pixel.rgbtGreen = clamp_pixel(round(green_sum / adj_pixel_count));
    pixel.rgbtBlue = clamp_pixel(round(blue_sum / adj_pixel_count));

    return pixel;
}

BYTE clamp_pixel(int rgb)
{
    if (rgb < 0) return 0;
    if (rgb > 255) return 255;
    return (BYTE) rgb;
}