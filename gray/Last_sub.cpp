// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name:			    Simple_Photoshop_Program.cpp
// Last Modification Date:	    17/10/2023
// Author1 and ID and Group:	Mohamed Taha    20221123 xxxxx
// Author2 and ID and Group:	Sherief Mahmoud 20221080 xxxxx
// Author3 and ID and Group:	Youssif waleed  20221206 xxxxx
// Teaching Assistant:		    xxxxx xxxxx
// Purpose:     A program of filters to apply on photos.
#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"
using namespace std;
unsigned char image[SIZE][SIZE];
unsigned char image1[SIZE][SIZE];
unsigned char image2[SIZE][SIZE];       // New image to store the filter effect.
unsigned char Blured_image[SIZE][SIZE]; // New image to store the filter effect.
unsigned char cpy[SIZE][SIZE];          // A copy of the original image to store the filter effect.
unsigned char Saved_image[SIZE][SIZE];
void loadImage1();
void loadImage();
void saveImage();
void Auto_saved_image();
void doSomethingForImage();
void Black_and_White_Filter()
{
    // Convert the gray image to black and white.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (image[i][j] > 128)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Invert_Filter()
{
    // get the negative value of every pixel in the image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = (255 - image[i][j]);
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Merge_Filter()
{
    loadImage1();
    // Merging two images.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = (image[i][j] + image1[i][j]) / 2; // Take the average of the corresponding pixels.
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
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
                swap(image[i][j], image[SIZE - i - 1][j]);
            }
        }
    }
    else if (Flip == 'h') // Horizontsl flip.
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE / 2; j++)
            {
                swap(image[i][j], image[i][SIZE - j - 1]);
            }
        }
    }
    else
    {
        cout << "Press (h) to flip the image horizontally OR (v) to flip it Vertically: ";
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
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
                image[i][j] /= 2;
            }
        }
    }
    else if (mode == 'l') // lighten flip.
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {

                image[i][j] = 128 + (image[i][j] / 2);
            }
        }
    }
    else
    {
        cout << "Press (d) to darken the image OR (l) to lighten the image: ";
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Rotate_Filter()
{
    // Rotate The image with degree according to user decision.
    int degree;
    cout << "Enter the degree you want to rotate (90 , 180 , 270): ";
    cin >> degree;
    if (degree == 90)
    {

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                image2[i][j] = image[i][j];
            }
        }
        for (int i = SIZE; i >= 0; --i)
        {
            for (int j = SIZE - 1; j >= 0; --j)
            {
                image[SIZE - i - 1][j] = image2[j][i];
            }
        }
    }
    else if (degree == 180)
    {
        int n = 2;
        while (n--)
        {

            for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                {
                    image2[i][j] = image[i][j];
                }
            }
            for (int i = SIZE; i >= 0; --i)
            {
                for (int j = SIZE - 1; j >= 0; --j)
                {
                    image[SIZE - i - 1][j] = image2[j][i];
                }
            }
        }
    }
    else if (degree == 270)
    {
        int n = 3;
        while (n--)
        {

            for (int i = 0; i < SIZE; ++i)
            {
                for (int j = 0; j < SIZE; ++j)
                {
                    image2[i][j] = image[i][j];
                }
            }
            for (int i = SIZE; i >= 0; --i)
            {
                for (int j = SIZE - 1; j >= 0; --j)
                {
                    image[SIZE - i - 1][j] = image2[j][i];
                }
            }
        }
    }
    else
    {
        cout << "Enter the degree you want to rotate (90 , 180 , 270): ";
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Edges_Filter()
{
    // Detect the edges of a black and white image.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (image[i][j] > 128)
            {
                image[i][j] = 255;
            }
            else
            {
                image[i][j] = 0;
            }
        }
    }
    unsigned char image2[SIZE][SIZE]; // New image set to white.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image2[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (image[i][j] == 0 && (image[i][j + 1] || image[i][j - 1] || image[i - 1][j] || image[i + 1][j]))
            {
                // Check if the pixel equals the surrounding pixels if so, then its not an edge.
                image2[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = image2[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Enlarge_image()
{
    // Enlarge a quarter of an image that user inserts.

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image2[i][j] = image[i][j];
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
                image[Rows][Columns] = image2[i][j];
                image[Rows][Columns + 1] = image2[i][j];
                image[Rows + 1][Columns] = image2[i][j];
                image[Rows + 1][Columns + 1] = image2[i][j];
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
                image[Rows][Columns] = image2[i][j];
                image[Rows][Columns + 1] = image2[i][j];
                image[Rows + 1][Columns] = image2[i][j];
                image[Rows + 1][Columns + 1] = image2[i][j];
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
                image[Rows][Columns] = image2[i][j];
                image[Rows][Columns + 1] = image2[i][j];
                image[Rows + 1][Columns] = image2[i][j];
                image[Rows + 1][Columns + 1] = image2[i][j];
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
                image[Rows][Columns] = image2[i][j];
                image[Rows][Columns + 1] = image2[i][j];
                image[Rows + 1][Columns] = image2[i][j];
                image[Rows + 1][Columns + 1] = image2[i][j];
                Columns += 2;
            }
            Rows += 2;
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Shrink_Filter()
{
    // Shrink an image to a size that user inserts.

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image2[i][j] = 255;
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
                int Average = (image[Rows][Columns] + image[Rows + 1][Columns] + image[Rows][Columns + 1] + image[Rows + 1][Columns + 1]) / 4;
                image2[i][j] = Average;
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
                int Average = 0;
                for (int k = Rows; k < Rows + 4; ++k)
                {
                    for (int l = Columns; l < Columns + 4; ++l)
                    {
                        Average += image[k][l];
                    }
                }
                image2[i][j] = Average / 16;
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
                int Average = 0;
                for (int k = Rows; k < Rows + 3; ++k)
                {
                    for (int l = Columns; l < Columns + 3; ++l)
                    {
                        Average += image[k][l];
                    }
                }
                image2[i][j] = Average / 9;
                Columns += 3;
            }
            Rows += 3;
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = image2[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
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
                image[i][255 - j] = image[i][j];
            }
        }
    }
    else if (Mirror == 'r')
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 255; j >= 128; --j)
            {
                image[i][255 - j] = image[i][j];
            }
        }
    }
    else if (Mirror == 'u')
    {
        for (int i = 0; i < 128; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                image[255 - i][j] = image[i][j];
            }
        }
    }
    else if (Mirror == 'd')
    {
        for (int i = 128; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                image[255 - i][j] = image[i][j];
            }
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Shuffle_Filter()
{
    // Shuffle the quarters of an image depending on the order user inserts.

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image2[i][j] = image[i][j];
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
                        image[j][k] = image2[j + 128][k + 128];
                    }
                }
            }
            else if (Order == 3)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        image[j][k] = image2[j + 128][k];
                    }
                }
            }
            else if (Order == 2)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        image[j][k] = image2[j][k + 128];
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
                        image[j][k] = image2[j + 128][k];
                    }
                }
            }
            else if (Order == 3)
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        image[j][k] = image2[j + 128][k - 128];
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
                        image[j][k] = image2[j][k - 128];
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
                        image[j][k] = image2[j][k + 128];
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
                        image[j][k] = image2[j - 128][k + 128];
                    }
                }
            }
            else if (Order == 1)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 0; k < 128; ++k)
                    {
                        image[j][k] = image2[j - 128][k];
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
                        image[j][k] = image2[j][k - 128];
                    }
                }
            }
            else if (Order == 2)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        image[j][k] = image2[j - 128][k];
                    }
                }
            }
            else if (Order == 1)
            {
                for (int j = 128; j < SIZE; ++j)
                {
                    for (int k = 128; k < SIZE; ++k)
                    {
                        image[j][k] = image2[j - 128][k - 128];
                    }
                }
            }
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Blur_Filter()
{
    // Blur an image.
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            Blured_image[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            int sum = 0; // store The summation of pixels to calculate the average.
            int counter = 0;
            for (int k = -3; k < 4; k++)
            {
                for (int h = -3; h < 4; h++)
                {
                    if (i + k < 0 or i + k > SIZE - 1 or j + h < 0 or j + h > SIZE - 1) // Avoid dealing with the outter pixels of the image.
                        continue;
                    sum += image[i + k][j + h];
                    counter++;
                }
            }
            Blured_image[i][j] = sum / counter;
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = Blured_image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Crop_Filter()
{
    // Crop an image to a size that user inserts.

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
            image2[i][j] = 255;
        }
    }
    for (int i = X; i < (X) + Length; i++)
    {
        for (int j = Y; j < (Y) + Width; j++)
        {
            image2[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = image2[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Skew_Filter_right()
{
    // Skew an image horizontally.
    cout << "Enter the degree: ";
    float deg;
    cin >> deg;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cpy[i][j] = 255;
        }
    }
    int Column_length = 1, Row_length = 256;
    double pi = 22 / 7.0;
    for (int i = 0; i < SIZE; i++, Row_length--, Column_length++)
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
                avg += image[i][w + k];
            }
            avg /= floor(pixels + remainder);
            if (j > 256 - rightangle)
            {
                break;
            }
            cpy[i][j++] = avg;
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
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = cpy[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
}
void Skew_Filter_up()
{
    // Skew an image vertically.
    cout << "Enter the degree: ";
    float deg;
    cin >> deg;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cpy[i][j] = 255;
        }
    }
    for (int i = 0; i < SIZE; i++) // to store the (Horizontal flip) filter effect.
    {
        for (int j = 0; j < SIZE / 2; j++)
        {
            swap(image[i][j], image[i][SIZE - j - 1]);
        }
    }
    unsigned char image2[SIZE][SIZE]; // New image to store the ( 90 degree rotate) filter effect.
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image2[i][j] = image[i][j];
        }
    }
    for (int i = SIZE; i >= 0; --i)
    {
        for (int j = SIZE - 1; j >= 0; --j)
        {
            image[SIZE - i - 1][j] = image2[j][i];
        }
    }
    int Column_length = 1, Row_length = 256;
    double pi = 22 / 7.0;
    for (int i = 0; i < SIZE; i++, Row_length--, Column_length++)
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
                avg += image[i][w + k];
            }
            avg /= floor(pixels + remainder);
            if (j > 256 - rightangle)
            {
                break;
            }
            cpy[j++][i] = avg;
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
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            image[i][j] = cpy[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            Saved_image[i][j] = image[i][j];
        }
    }
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
         << "g- Save image.\n"
         << "0- Exit\n";
    char num_filter;
    loadImage();
    while (true)
    {
        cout << "Select a filter number from the list to apply or 0 to exit: ";
        cin >> num_filter;
        string s = "";
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
        else if (num_filter == 'g')
        {
            Auto_saved_image();
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
    readGSBMP(imageFileName, image);
}
void loadImage1()
{
    char imageFileName[100];
    // Get gray scale image file name
    cout << "Enter the source image file name you want to merge with: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    readGSBMP(imageFileName, image1);
}
//_________________________________________
void Auto_saved_image()
{
    char imageFileName[100];
    // Get gray scale image target file name
    cout << "Enter the target image file name: ";
    cin >> imageFileName;
    // Add to it .bmp extension and load image
    strcat(imageFileName, ".bmp");
    writeGSBMP(imageFileName, Saved_image);
}
