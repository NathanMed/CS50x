#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int RGB_AVG = round((image[h][w].rgbtBlue + image[h][w].rgbtRed + image[h][w].rgbtGreen) / 3.0);
            image[h][w].rgbtBlue = RGB_AVG;
            image[h][w].rgbtRed = RGB_AVG;
            image[h][w].rgbtGreen = RGB_AVG;
        }
    }
    return;
}

//makes sure the rgb value is between 0 and 255
int max(int value)
{
    if (value > 255)
    {
        return 255;
    }
    else
    {
        return value;
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //Conversion of all colors to their respective sepia colors
            int SepiaBlue = max(round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue));
            int SepiaGreen = max(round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue));
            int SepiaRed = max(round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue));
            //Actually sets the rgbt values as the sepia ones
            image[h][w].rgbtBlue = SepiaBlue;
            image[h][w].rgbtGreen = SepiaGreen;
            image[h][w].rgbtRed = SepiaRed;
            
        }
    }
    return;
}

//swaps the values of the given pixels
void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w  = 0; w < width / 2; w++)
        {
            swap(&image[h][w], &image[h][width - 1 - w]);
        }
    }
}

//Makes sure the pixel is in the bounds of the picture
bool validpixel(int h, int w, int i, int j)
{
    if (i < h && i >= 0 && j < w && j >= 0)
    {
        return true;
    }
    return false; 
}

//Actually blurs the pixel by average the RGB values of the pixels around it
RGBTRIPLE blurpixel(int height, int width, int i, int j, RGBTRIPLE image[height][width])
{
    //declaring rgb values
    int blue = 0;
    int red = 0;
    int green = 0;
    //the number of valid pixels
    int validPixelCount = 0;
    for (int k = -1; k <= 1; k++)
    {
        for (int w = -1; w <= 1; w++)
        {
            int new_i = i + k;
            int new_j = j + w;
            if (validpixel(height, width, new_i, new_j))
            {
                validPixelCount++;
                red += image[new_i][new_j].rgbtRed;
                blue += image[new_i][new_j].rgbtBlue;
                green += image[new_i][new_j].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blurred_pixel;
    //averages the rgb values of all near by valid pixels
    blurred_pixel.rgbtRed = round((float)red / validPixelCount);
    blurred_pixel.rgbtBlue = round((float)blue / validPixelCount);
    blurred_pixel.rgbtGreen = round((float)green / validPixelCount);
    return blurred_pixel;
}

//converts the given image to a blurred version pixel by pixel
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            new_image[h][w] = blurpixel(height, width, h, w, image);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
    return;
}
