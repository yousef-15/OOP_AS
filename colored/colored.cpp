// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:			    First_Six_Filters.cpp
// Last Modification Date:	    14/10/2023
// Author1 and ID and Group:	Mohamed Taha    20221123 xxxxx
// Author2 and ID and Group:	Sherief Mahmoud 20221080 xxxxx
// Author3 and ID and Group:	Youssif waleed  20221206 xxxxx
// Teaching Assistant:		    xxxxx xxxxx
// Purpose:     A program of filters to apply on photos
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image1[SIZE][SIZE][RGB];
void loadImage1();
void loadImage();
void saveImage();
void doSomethingForImage();
void Black_and_White_Filter()
{
    // Convert the gray image to black and white.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int avg = (image[i][j][0] + image[i][j][1] + image[i][j][2]) / RGB;
            if (avg < 128)
            {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
            else
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
        }
    }
    saveImage();
}
void Invert_Filter()
{
    // get the negative value of every pixel in the image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < SIZE; ++k)
            {
                image[i][j][k] = 255 - image[i][j][k];
            }
        }
    }
    saveImage();
}
void Merge_Filter()
{
    loadImage1();
    // Merging two images.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                image[i][j][k] = (image[i][j][k] + image1[i][j][k]) / 2;
            }
        }
    }
    saveImage();
}
void Flip_Filter()
{
    // Flip The image according to user decision.
    char Flip;
    cout << "Press (h) to flip the image horizontally OR (v) to flip it Vertically: ";
    cin >> Flip;
    if (Flip == 'v') // Vertical flip.
    {
        for (int i = 0; i < SIZE / 2; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    swap(image[i][j][k], image[SIZE - i - 1][j][k]);
                }
            }
        }
    }
    else if (Flip == 'h') // Horizontsl flip.
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                for (int k = 0; k < RGB; k++)
                {
                    swap(image[i][j][k], image[i][SIZE - j - 1][k]);
                }
            }
        }
    }
    else
    {
        cout << "Press (h) to flip the image horizontally OR (v) to flip it Vertically: ";
    }
    saveImage();
}
void Darken_Lighten_Filter()
{
    // Darken orLighten The image according to user decision.
    cout << "Press (d) to darken the image OR (l) to lighten the image: ";
    char mode;
    cin >> mode;
    if (mode == 'd') // Darken.
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[i][j][k] = image[i][j][k] / 2;
                }
            }
        }
    }
    else if (mode == 'l') // lighten flip.
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[i][j][k] = (image[i][j][k] + 220) / 2;
                }
            }
        }
    }
    else
    {
        cout << "Press (d) to darken the image OR (l) to lighten the image: ";
    }
    saveImage();
}
void Rotate_Filter()
{
    // Rotate The image with degree according to user decision.
    int degree;
    cout << "Enter the degree you want to rotate (90 , 180 , 270): ";
    cin >> degree;
    unsigned char image2[SIZE][SIZE][RGB]; // New image to store the filter effect.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    if (degree == 90)
    {

        for (int i = SIZE; i >= 0; --i)
        {
            for (int j = SIZE - 1; j >= 0; --j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[SIZE - i - 1][j][k] = image2[j][i][k];
                }
            }
        }
    }
    else if (degree == 180)
    {
        int n = 2;
        while (n--)
        {

            for (int i = SIZE; i >= 0; --i)
            {
                for (int j = SIZE - 1; j >= 0; --j)
                {
                    for (int k = 0; k < RGB; ++k)
                    {
                        image[SIZE - i - 1][j][k] = image2[j][i][k];
                    }
                }
            }
        }
    }
    else if (degree == 270)
    {
        int n = 3;
        while (n--)
        {
            for (int i = SIZE; i >= 0; --i)
            {
                for (int j = SIZE - 1; j >= 0; --j)
                {
                    for (int k = 0; k < RGB; ++k)
                    {
                        image[SIZE - i - 1][j][k] = image2[j][i][k];
                    }
                }
            }
        }
    }
    else
    {
        cout << "Enter the degree you want to rotate (90 , 180 , 270): ";
    }
    saveImage();
}
void Edges_Filter()
{
    // Detect the edges of a black and white image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            int avg = (image[i][j][0] + image[i][j][1] + image[i][j][2]) / RGB;
            if (avg < 128)
            {
                image[i][j][0] = 0;
                image[i][j][1] = 0;
                image[i][j][2] = 0;
            }
            else
            {
                image[i][j][0] = 255;
                image[i][j][1] = 255;
                image[i][j][2] = 255;
            }
        }
    }
    unsigned char image2[SIZE][SIZE][RGB]; // New image set to white.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                image2[i][j][k] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; ++k)
            {
                if (image[i][j][k] == 0 && (image[i][j + 1][k] || image[i][j - 1][k] || image[i - 1][j][k] || image[i + 1][j][k]))
                {
                    // Check if the pixels surrounding pixel we are on is on, then its an edge.
                    image2[i][j][k] = 0;
                }
            }
        }
    }
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}
void Enlarge_image()
{
    // Enlarge a quarter of an image that user inserts.
    unsigned char image2[SIZE][SIZE][RGB]; // New image to store the filter effect.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    int quarter;
    cout << "Enter the quarter you want to enlarge: ";
    cin >> quarter;
    int Rows = 0, Columns = 0;
    if (quarter == 1)
    {
        for (int i = 0; i < 128; ++i)
        {
            Columns = 0;
            for (int j = 0; j < 128; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[Rows][Columns][k] = image2[i][j][k];
                    image[Rows][Columns + 1][k] = image2[i][j][k];
                    image[Rows + 1][Columns][k] = image2[i][j][k];
                    image[Rows + 1][Columns + 1][k] = image2[i][j][k];
                }
                Columns += 2;
            }
            Rows += 2;
        }
    }
    else if (quarter == 2)
    {

        for (int i = 0; i < 128; ++i)
        {
            Columns = 0;
            for (int j = 128; j < 256; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[Rows][Columns][k] = image2[i][j][k];
                    image[Rows][Columns + 1][k] = image2[i][j][k];
                    image[Rows + 1][Columns][k] = image2[i][j][k];
                    image[Rows + 1][Columns + 1][k] = image2[i][j][k];
                }
                Columns += 2;
            }
            Rows += 2;
        }
    }
    else if (quarter == 3)
    {
        for (int i = 128; i < 256; ++i)
        {
            Columns = 0;
            for (int j = 0; j < 128; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[Rows][Columns][k] = image2[i][j][k];
                    image[Rows][Columns + 1][k] = image2[i][j][k];
                    image[Rows + 1][Columns][k] = image2[i][j][k];
                    image[Rows + 1][Columns + 1][k] = image2[i][j][k];
                }
                Columns += 2;
            }
            Rows += 2;
        }
    }
    else if (quarter == 4)
    {
        for (int i = 128; i < 256; ++i)
        {
            Columns = 0;
            for (int j = 128; j < 256; ++j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[Rows][Columns][k] = image2[i][j][k];
                    image[Rows][Columns + 1][k] = image2[i][j][k];
                    image[Rows + 1][Columns][k] = image2[i][j][k];
                    image[Rows + 1][Columns + 1][k] = image2[i][j][k];
                }
                Columns += 2;
            }
            Rows += 2;
        }
    }
    saveImage();
}
void Blur_Filter()
{
    // Blur an image.
    unsigned char Blured_image[SIZE][SIZE][RGB]; // New image to store the filter effect.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                Blured_image[i][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int z = 0; z < RGB; z++)
            {
                int sum = 0; // store The summation of pixels to calculate the average.
                int counter = 0;
                for (int k = -3; k < 4; k++)
                {
                    for (int h = -3; h < 4; h++)
                    {
                        if (i + k < 0 or i + k > SIZE - 1 or j + h < 0 or j + h > SIZE - 1) // Avoid dealing with the outter pixels of the image.
                            continue;
                        sum += image[i + k][j + h][z];
                        counter++;
                    }
                }
                Blured_image[i][j][z] = sum / counter;
            }
        }
    }
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, Blured_image);
}
void Shrink_Filter()
{
    // Shrink an image to a size that user inserts.
    unsigned char image2[SIZE][SIZE][RGB]; // New image to store the filter effect.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                image2[i][j][k] = 255;
            }
        }
    }
    cout << "Enter the size you want to shrink (1/2 , 1/3 , 1/4 ): ";
    string shrink;
    cin >> shrink;
    int Rows = 0, Columns = 0;
    if (shrink == "1/2")
    {
        for (int i = 0; i < 128; ++i)
        {
            Columns = 0;
            for (int j = 0; j < 128; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    int Average = (image[Rows][Columns][k] + image[Rows + 1][Columns][k] + image[Rows][Columns + 1][k] + image[Rows + 1][Columns + 1][k]) / 4;
                    image2[i][j][k] = Average;
                }
                Columns += 2;
            }
            Rows += 2;
        }
    }
    else if (shrink == "1/4")
    {
        for (int i = 0; i < 64; i++)
        {
            Columns = 0;
            for (int j = 0; j < 64; j++)
            {
                for (int z = 0; z < RGB; z++)
                {
                    int Average = 0;
                    for (int k = Rows; k < Rows + 4; ++k)
                    {
                        for (int l = Columns; l < Columns + 4; ++l)
                        {
                            Average += image[k][l][z];
                        }
                    }
                    image2[i][j][z] = Average / 16;
                }
                Columns += 4;
            }
            Rows += 4;
        }
    }
    else if (shrink == "1/3")
    {
        for (int i = 0; i < 85; i++)
        {
            Columns = 0;
            for (int j = 0; j < 85; j++)
            {
                for (int z = 0; z < RGB; z++)
                {
                    int Average = 0;
                    for (int k = Rows; k < Rows + 3; ++k)
                    {
                        for (int l = Columns; l < Columns + 3; ++l)
                        {
                            Average += image[k][l][z];
                        }
                    }
                    image2[i][j][z] = Average / 9;
                }
                Columns += 3;
            }
            Rows += 3;
        }
    }
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}
void Shuffle_Filter()
{
    // Shuffle the quarters of an image depending on the order user inserts.
    unsigned char image2[SIZE][SIZE][RGB]; // New image to store the filter effect.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; ++k)
            {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    int n = 4;
    cout << "Enter the order of quarters you want seperated by white spaces: ";
    int Order;
    for (int i = 1; i <= n; ++i) // i is the quarter we work on.
    {
        cin >> Order;
        if (i == 1)
        {
            if (Order == 4)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j + 128][k + 128][h];
                        }
                    }
                }
            }
            else if (Order == 3)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j + 128][k][h];
                        }
                    }
                }
            }
            else if (Order == 2)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j][k + 128][h];
                        }
                    }
                }
            }
            else if (Order == 1)
            {
                continue;
            }
        }
        else if (i == 2)
        {
            if (Order == 4)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j + 128][k][h];
                        }
                    }
                }
            }
            else if (Order == 3)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j + 128][k - 128][h];
                        }
                    }
                }
            }
            else if (Order == 2)
            {
                continue;
            }
            else if (Order == 1)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j][k - 128][h];
                        }
                    }
                }
            }
        }
        else if (i == 3)
        {
            if (Order == 4)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j][k + 128][h];
                        }
                    }
                }
            }
            else if (Order == 3)
            {
                continue;
            }
            else if (Order == 2)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j - 128][k + 128][h];
                        }
                    }
                }
            }
            else if (Order == 1)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j - 128][k][h];
                        }
                    }
                }
            }
        }
        else if (i == 4)
        {
            if (Order == 4)
            {
                continue;
            }
            else if (Order == 3)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j][k - 128][h];
                        }
                    }
                }
            }
            else if (Order == 2)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j - 128][k][h];
                        }
                    }
                }
            }
            else if (Order == 1)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        for (int h = 0; h < RGB; h++)
                        {
                            image[j][k][h] = image2[j - 128][k - 128][h];
                        }
                    }
                }
            }
        }
    }
    saveImage();
}
void Crop_Filter()
{
    // Crop an image to a size that user inserts.
    unsigned char image2[SIZE][SIZE][RGB]; // New image to store the filter effect.
    int X, Y, Width, Length;
    cout << "Enter the X coordinate: ";
    cin >> X;
    cout << "Enter the Y coordinate: ";
    cin >> Y;
    cout << "Enter the Length: ";
    cin >> Length;
    cout << "Enter the Width: ";
    cin >> Width;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                image2[i][j][k] = 255;
            }
        }
    }
    for (int i = X; i < (X) + Length; i++)
    {
        for (int j = Y; j < (Y) + Width; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image2);
}
void Mirror_Filter()
{
    // Mirrors an image according to user choice.
    cout << "Enter how u want to mirror the image ((l)eft, (r)ight, (u)pper, (d)own side): ";
    char Mirror;
    cin >> Mirror;
    if (Mirror == 'l')
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 127; j >= 0; --j)
            {
                for (int k = 0; k < RGB; ++k)
                {
                    image[i][255 - j][k] = image[i][j][k];
                }
            }
        }
    }
    else if (Mirror == 'r')
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 255; j >= 128; --j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[i][255 - j][k] = image[i][j][k];
                }
            }
        }
    }
    else if (Mirror == 'u')
    {
        for (int i = 0; i < 128; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[255 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    else if (Mirror == 'd')
    {
        for (int i = 128; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                for (int k = 0; k < RGB; k++)
                {
                    image[255 - i][j][k] = image[i][j][k];
                }
            }
        }
    }
    saveImage();
}
void Skew_Filter_right()
{
    // Skew an image horizontally.
    cout << "Enter the degree: ";
    float deg;
    cin >> deg;
    unsigned char copy[SIZE][SIZE][RGB]; // A copy of the original image to store the filter effect.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int z = 0; z < RGB; z++)
            {
                copy[i][j][z] = 255;
            }
        }
    }
    int Column_length = 1, Row_length = 256;
    double pi = 22 / 7.0;
    for (int i = 0; i < SIZE; i++, Row_length--, Column_length++)
    {
        for (int h = 0; h < RGB; h++)
        {
            int leftangle = (tan(deg * (pi / 180.0)) * Row_length); // Transform from degree to radiant in tan.
            int rightangle = (tan(deg * (pi / 180.0)) * Column_length);
            double pixels = 256.0 / (256 - (leftangle + rightangle));
            double remainder = 0;
            int j = leftangle;
            for (int k = 0; k < SIZE; k += floor(pixels + remainder))
            {

                int avg = 0;
                for (int w = 0; w < floor(pixels + remainder); w++)
                {
                    avg += image[i][w + k][h];
                }
                avg /= floor(pixels + remainder);
                if (j > 256 - rightangle)
                {
                    break;
                }
                copy[i][j++][h] = avg;
                if ((int)(pixels + remainder) < (int)pixels)
                {
                    remainder += pixels - (int)pixels;
                }
                else
                {
                    remainder -= (int)(remainder + pixels) - pixels;
                }
            }
        }
    }
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, copy);
}
void Skew_Filter_up()
{
    // Skew an image vertically.
    cout << "Enter the degree: ";
    float deg;
    cin >> deg;
    unsigned char copy[SIZE][SIZE][RGB]; // A copy of the original image to store the filter effect.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int z = 0; z < RGB; z++)
            {
                copy[i][j][z] = 255;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) // to store the (Horizontal flip) filter effect.
    {
        for (int j = 0; j < SIZE / 2; j++)
        {
            swap(image[i][j], image[i][SIZE - j - 1]);
        }
    }
    unsigned char image2[SIZE][SIZE][RGB]; // New image to store the ( 90 degree rotate) filter effect.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            for (int k = 0; k < RGB; k++)
            {
                image2[i][j][k] = image[i][j][k];
            }
        }
    }
    for (int i = SIZE; i >= 0; --i)
    {
        for (int j = SIZE - 1; j >= 0; --j)
        {
            for (int k = 0; k < RGB; k++)
            {
                image[SIZE - i - 1][j][k] = image2[j][i][k];
            }
        }
    }
    int Column_length = 1, Row_length = 256;
    double pi = 22 / 7.0;
    for (int i = 0; i < SIZE; i++, Row_length--, Column_length++)
    {
        for (int h = 0; h < RGB; h++)
        {
            int leftangle = (tan(deg * (pi / 180.0)) * Row_length); // Transform from degree to radiant in tan.
            int rightangle = (tan(deg * (pi / 180.0)) * Column_length);
            double pixels = 256.0 / (256 - (leftangle + rightangle));
            double remainder = 0;
            int j = leftangle;
            for (int k = 0; k < SIZE; k += floor(pixels + remainder))
            {

                int avg = 0;
                for (int w = 0; w < floor(pixels + remainder); w++)
                {
                    avg += image[i][w + k][h];
                }
                avg /= floor(pixels + remainder);
                if (j > 256 - rightangle)
                {
                    break;
                }
                copy[j++][i][h] = avg;
                if ((int)(pixels + remainder) < (int)pixels)
                {
                    remainder += pixels - (int)pixels;
                }
                else
                {
                    remainder -= (int)(remainder + pixels) - pixels;
                }
            }
        }
    }
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, copy);
}
int main()
{
    cout << "Welcome to our filter program.\n";
    cout << "Please choose what filter you want to apply on your image: \n";
    cout << "1- Black & White Filter. \n"
         << "2- Invert Filter.\n"
         << "3- Merge Filter. \n"
         << "4- Flip Image.\n"
         << "5- Darken and Lighten Image. \n"
         << "6- Rotate Image.\n"
         << "7- Detect Image Edges. \n"
         << "8- Enlarge Image. \n"
         << "9- Shrink Image.\n"
         << "a- Mirror 1/2 Image. \n"
         << "b- Shuffle Image.\n"
         << "c- Blur Image.\n"
         << "d- Crop Image.\n"
         << "e- Skew Image Right. \n"
         << "f- Skew Image Up.\n"
         << "0- Exit\n";
    char num_filter;
    loadImage();
    while (true)
    {
        cout << "Select a filter number from the list to apply or 0 to exit: ";
        cin >> num_filter;
        if (num_filter == '1')
        {
            Black_and_White_Filter();
        }
        else if (num_filter == '2')
        {
            Invert_Filter();
        }
        else if (num_filter == '3')
        {
            Merge_Filter();
        }
        else if (num_filter == '4')
        {
            Flip_Filter();
        }
        else if (num_filter == '5')
        {
            Darken_Lighten_Filter();
        }
        else if (num_filter == '6')
        {
            Rotate_Filter();
        }
        else if (num_filter == '7')
        {
            Edges_Filter();
        }
        else if (num_filter == '8')
        {
            Enlarge_image();
        }
        else if (num_filter == '9')
        {
            Shrink_Filter();
        }
        else if (num_filter == 'a')
        {
            Mirror_Filter();
        }
        else if (num_filter == 'b')
        {
            Shuffle_Filter();
        }
        else if (num_filter == 'c')
        {
            Blur_Filter();
        }
        else if (num_filter == 'd')
        {
            Crop_Filter();
        }
        else if (num_filter == 'e')
        {
            Skew_Filter_right();
        }
        else if (num_filter == 'f')
        {
            Skew_Filter_up();
        }
        else
        {
            break;
        }
    }
    return 0;
}
//_________________________________________
void loadImage()
{
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
void loadImage1()
{
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name you want to merge with: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);
}
//_________________________________________
void saveImage()
{
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeRGBBMP(imageFileName, image);
}