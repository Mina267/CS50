#include "helpers.h"
#include <math.h>

int average(int x, int y, int i, int j, int height, int width, RGBTRIPLE image[height][width]);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0; j < width; j++)
        {
            //calc. average of the pixel color
            int av = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = av;
            image[i][j].rgbtGreen = av;
            image[i][j].rgbtBlue = av;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0; j < width; j++)
        {
            //sepia formula
            int sepiaRed = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen + 0.189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen + 0.168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen + 0.131 * image[i][j].rgbtBlue);
            
            //check if any color exceed one byte 255
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0, W = round(width / 2); j < W ; j++)
        {
            // store first and last pixel in temprary storage
            RGBTRIPLE temp1 = image[i][j];
            RGBTRIPLE temp2 = image [i][(width - 1) - j];
            image[i][j] = temp2;
            image [i][(width - 1) - j] = temp1;
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //temp for store image
    RGBTRIPLE temp[height][width];
    
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0; j < width; j++)
        {
            // constant for calc. 
            float R = 0, G = 0, B = 0, c = 0;
            
            for (int k = -1; k < 2; k++)
            {
                for (int m = - 1; m < 2; m++)
                {
                    // if one of this contion is true stop loop
                    if (i + k < 0 || i + k > (height - 1) || j + m > (width - 1) || j + m < 0)
                    {
                        continue;
                    }
                    
                    R += image[i + k][j + m].rgbtRed;
                    G += image[i + k][j + m].rgbtGreen;
                    B += image[i + k][j + m].rgbtBlue;
                    c++;
                }    
            }
            temp[i][j].rgbtRed = round(R / c);
            temp[i][j].rgbtGreen = round(G / c);
            temp[i][j].rgbtBlue = round(B / c);
        }
    }    
        
    // copy temp to image    
    for (int i = 0; i < height; i++)
    {
        
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        
        }
    }    
}