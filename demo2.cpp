// Program: demo2.cpp
// Purpose: Demonstrate use of bmplip for handling
//          bmp colored and grayscale images
//          Program load a gray image and store in another file
// Author:  Mohammad El-Ramly
// Date:    30 March 2018
// Version: 1.0

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE][RGB];
unsigned char image1[SIZE][SIZE][RGB];
void loadImage1 ();
void loadImage ();
void saveImage ();
void doSomethingForImage ();
int row[] = {1 ,-1 ,0 ,0 ,1 ,1, -1, -1};
int col[] = {0 ,0 ,1 ,-1 ,1 ,-1 ,1 ,-1};
void B_W_img(){
    loadImage();
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            for (int k = 0; k < RGB; ++k) {
                if(image[i][j][k] > 128){
                    image[i][j][k] = 255;
                }
                else{
                    image[i][j][k] = 0;
                }
            }
        }
    }
    saveImage();
}
//void Merge_img(){
//    loadImage();
//    loadImage1();
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            image[i][j] = (image[i][j] + image1[i][j])/2;
//        }
//    }
//    saveImage();
//}
//void Invert_img(){
//    loadImage();
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            image[i][j] = (255-image[i][j]);
//        }
//    }
//    saveImage();
//}
//void Flip_img(){
//    loadImage();
//    char Flip;
//    cout << "Please choose how you want to show the image vertically or horizontally press v for vertically or press h for horizontally: ";
//    cin >> Flip;
//    if(Flip == 'v'){
//        unsigned char image2[SIZE][SIZE];
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image2[i][j] = image[i][j];
//            }
//        }
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image[i][j] = image2[SIZE-i-1][j];
//            }
//        }
//        saveImage();
//    }
//    else if(Flip == 'h'){
//        unsigned char image2[SIZE][SIZE];
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image2[i][j] = image[i][j];
//            }
//        }
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image[i][j] = image2[i][SIZE-j-1];
//            }
//        }
//        saveImage();
//    }
//    else{
//        cout << "please press v for vertical or h for horizontal\n";
//    }
//}
//void Rotate_img(){
//    loadImage();
//    int  degree;
//    cout << "please choose the degree you want: ";
//    cin >> degree;
//    if(degree == 90){
//        unsigned char image2[SIZE][SIZE];
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image2[i][j] = image[i][j];
//            }
//        }
//        for (int i = SIZE; i >= 0; --i) {
//            for (int j = SIZE-1; j >= 0; --j) {
//                image[SIZE-i-1][j] = image2[j][i];
//            }
//        }
//        saveImage();
//    }
//    else if(degree == 180){
//        int n = 2;
//        while (n--){
//            unsigned char image2[SIZE][SIZE];
//            for (int i = 0; i < SIZE; ++i) {
//                for (int j = 0; j < SIZE; ++j) {
//                    image2[i][j] = image[i][j];
//                }
//            }
//            for (int i = SIZE; i >= 0; --i) {
//                for (int j = SIZE-1; j >= 0; --j) {
//                    image[SIZE-i-1][j] = image2[j][i];
//                }
//            }
//        }
//        saveImage();
//    }
//    else if(degree == 270){
//        int n = 3;
//        while (n--){
//            unsigned char image2[SIZE][SIZE];
//            for (int i = 0; i < SIZE; ++i) {
//                for (int j = 0; j < SIZE; ++j) {
//                    image2[i][j] = image[i][j];
//                }
//            }
//            for (int i = SIZE; i >= 0; --i) {
//                for (int j = SIZE-1; j >= 0; --j) {
//                    image[SIZE-i-1][j] = image2[j][i];
//                }
//            }
//        }
//        saveImage();
//    }
//}
//void Darken_Lighten_img(){
//    loadImage();
//    cout << "choose your mode lighten or Darken: ";
//    string mode;
//    cin >> mode;
//    if(mode == "Darken"){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                if(image[i][j] > 128){
//                    image[i][j] -= 128;
//                }
//                else{
//                    image[i][j] = 0;
//                }
//            }
//        }
//        saveImage();
//    }
//    else if(mode == "lighten"){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                if(image[i][j] >= 128){
//                    image[i][j] = 255;
//                }
//                else{
//                    image[i][j] += 128;
//                }
//            }
//        }
//        saveImage();
//    }
//}
//void Edges_img()
//{
//    loadImage();
//    for (int i = 0; i < SIZE; ++i)
//    {
//        for (int j = 0; j < SIZE; ++j)
//        {
//            if (image[i][j] > 127)
//            {
//                image[i][j] = 255;
//            }
//            else
//            {
//                image[i][j] = 0;
//            }
//        }
//    }
//    unsigned char cpy[SIZE][SIZE];
//    for (int i = 0; i < SIZE; i++)
//    {
//        for (int j = 0; j < SIZE; j++)
//        {
//            if (image[i][j] == image[i + 1][j + 1] && image[i][j] == image[i + 1][j] && image[i][j] == image[i - 1][j + 1] && image[i][j] == image[i + 1][j - 1] && image[i][j] == image[i - 1][j - 1] && image[i][j] == image[i][j + 1] && image[i][j] == image[i - 1][j] && image[i][j] == image[i][j - 1])
//                cpy[i][j] = 255;
//            else
//                cpy[i][j] = 0;
//        }
//    }
//    char imageFileName[100];
//
//// Get gray scale image target file name
//    cout << "Enter the target image file name: ";
//    cin >> imageFileName;
//
//// Add to it .bmp extension and load image
//    strcat(imageFileName, ".bmp");
//    writeGSBMP(imageFileName, cpy);
//}
//void Enlarge_image(){
//    loadImage();
//    unsigned char image2[SIZE][SIZE];
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            image2[i][j] = image[i][j];
//        }
//    }
//    int quarter;
//    cout << "choose what quarter you want: ";
//    cin >> quarter;
//    if(quarter == 1){
//        int r=0,c=0;
//        for (int i = 0; i < 128; ++i) {
//            c=0;
//            for (int j = 0; j < 128; ++j) {
//                image[r][c] = image2[i][j];
//                image[r][c+1] = image2[i][j];
//                image[r+1][c] = image2[i][j];
//                image[r+1][c+1] = image2[i][j];
//                c+=2;
//            }
//            r+=2;
//        }
//        saveImage();
//    }
//    else if(quarter == 2){
//        int r=0,c=0;
//        for (int i = 0; i < 128; ++i) {
//            c=0;
//            for (int j = 128; j < 256; ++j) {
//                image[r][c] = image2[i][j];
//                image[r][c+1] = image2[i][j];
//                image[r+1][c] = image2[i][j];
//                image[r+1][c+1] = image2[i][j];
//                c+=2;
//            }
//            r+=2;
//        }
//        saveImage();
//    }
//    else if(quarter == 3){
//        int r=0,c=0;
//        for (int i = 128; i < 256; ++i) {
//            c=0;
//            for (int j = 0; j < 128; ++j) {
//                image[r][c] = image2[i][j];
//                image[r][c+1] = image2[i][j];
//                image[r+1][c] = image2[i][j];
//                image[r+1][c+1] = image2[i][j];
//                c+=2;
//            }
//            r+=2;
//        }
//        saveImage();
//    }
//    else if(quarter == 4){
//        int r=0,c=0;
//        for (int i = 128; i < 256; ++i) {
//            c=0;
//            for (int j = 128; j < 256; ++j) {
//                image[r][c] = image2[i][j];
//                image[r][c+1] = image2[i][j];
//                image[r+1][c] = image2[i][j];
//                image[r+1][c+1] = image2[i][j];
//                c+=2;
//            }
//            r+=2;
//        }
//        saveImage();
//    }
//}
//void Blur_img(){
//    loadImage();
//    unsigned char temp[SIZE][SIZE];
//    for(int i= 0 ;i<SIZE;i++){
//        for(int j =0 ; j <SIZE ; j++){
//            temp[i][j]= image[i][j];
//        }
//    }
//    for (int i = 0; i < SIZE; i++) {
//        for (int j = 0; j< SIZE; j++) {
//            int sum = 0 ;
//            int counter = 0 ;
//            for(int k = -3 ; k < 4 ;k++){
//                for(int h = -3; h < 4 ; h++ ){
//                    if(i+k <0 or i+k > SIZE-1 or j+h <0 or j+h> SIZE-1) continue;
//                    sum += image[i+k][j+h];
//                    counter++;
//                }
//            }
//            temp[i][j] = sum / counter;
//        }
//    }
//    for(int i= 0 ;i<SIZE;i++){
//        for(int j =0 ; j <SIZE ; j++){
//            image[i][j] = temp[i][j];
//        }
//    }
//    saveImage();
//}
//void Shrink_img(){
//    loadImage();
//    unsigned char image2[SIZE][SIZE];
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            image2[i][j] = 255;
//        }
//    }
//    cout << "please choose how you want to shrink half or quarter or third: ";
//    string shrink;
//    cin >> shrink;
//    if(shrink == "half"){
//        int r=0,c=0;
//        for (int i = 0; i < 128; ++i) {
//            c=0;
//            for (int j = 0; j < 128; ++j) {
//                int avr = (image[r][c]+image[r+1][c]+image[r][c+1]+image[r+1][c+1])/4;
//                image2[i][j] = avr;
//                c+=2;
//            }
//            r+=2;
//        }
//        char imageFileName[100];
//        // Get gray scale image target file name
//        cout << "Enter the target image file name: ";
//        cin >> imageFileName;
//        // Add to it .bmp extension and load image
//        strcat (imageFileName, ".bmp");
//        writeGSBMP(imageFileName, image2);
//    }
//    else if(shrink == "quarter"){
//        int r=0,c=0;
//        for (int i = 0; i < 64; i++) {
//            c=0;
//            for (int j = 0; j < 64; j++) {
//                int avr = 0;
//                for (int k = r; k < r+4; ++k) {
//                    for (int l = c; l < c+4; ++l) {
//                       avr+=image[k][l];
//                    }
//                }
//                image2[i][j] = avr/16;
//                c+=4;
//            }
//            r+=4;
//        }
//        char imageFileName[100];
//        // Get gray scale image target file name
//        cout << "Enter the target image file name: ";
//        cin >> imageFileName;
//        // Add to it .bmp extension and load image
//        strcat (imageFileName, ".bmp");
//        writeGSBMP(imageFileName, image2);
//    }
//    else if(shrink == "third"){
//        int r=0,c=0;
//        for (int i = 0; i < 85; i++) {
//            c=0;
//            for (int j = 0; j < 85; j++) {
//                int avr = 0;
//                for (int k = r; k < r+3; ++k) {
//                    for (int l = c; l < c+3; ++l) {
//                        avr+=image[k][l];
//                    }
//                }
//                image2[i][j] = avr/9;
//                c+=3;
//            }
//            r+=3;
//        }
//        char imageFileName[100];
//        // Get gray scale image target file name
//        cout << "Enter the target image file name: ";
//        cin >> imageFileName;
//        // Add to it .bmp extension and load image
//        strcat (imageFileName, ".bmp");
//        writeGSBMP(imageFileName, image2);
//    }
//}
//void Shuffle_img(){
//    loadImage();
//    unsigned char image2[SIZE][SIZE];
//    for (int i = 0; i < SIZE; ++i) {
//        for (int j = 0; j < SIZE; ++j) {
//            image2[i][j] = image[i][j];
//        }
//    }
//    int n = 4;
//    cout << "please enter your order from 1 to 4: ";
//    for (int i = 1; i <= n; ++i) {
//        int ord;
//        cin >> ord;
//        if(i == 1){
//            if(ord == 4){
//                for (int j = 0; j < 128; ++j) {
//                    for (int k = 0; k < 128; ++k) {
//                        image[j][k] = image2[j+128][k+128];
//                    }
//                }
//            }
//            else if(ord == 3){
//                for (int j = 0; j < 128; ++j) {
//                    for (int k = 0; k < 128; ++k) {
//                        image[j][k] = image2[j+128][k];
//                    }
//                }
//            }
//            else if(ord == 2){
//                for (int j = 0; j < 128; ++j) {
//                    for (int k = 0; k < 128; ++k) {
//                        image[j][k] = image2[j][k+128];
//                    }
//                }
//            }
//            else if(ord == 1){
//                continue;
//            }
//        }
//        else if(i == 2){
//            if(ord == 4){
//                for (int j = 0; j < 128; ++j) {
//                    for (int k = 128; k < SIZE; ++k) {
//                        image[j][k] = image2[j+128][k];
//                    }
//                }
//            }
//            else if(ord == 3){
//                for (int j = 0; j < 128; ++j) {
//                    for (int k = 128; k < SIZE; ++k) {
//                        image[j][k] = image2[j+128][k-128];
//                    }
//                }
//            }
//            else if(ord == 2){
//                continue;
//            }
//            else if(ord == 1){
//                for (int j = 0; j < 128; ++j) {
//                    for (int k = 128; k < SIZE; ++k) {
//                        image[j][k] = image2[j][k-128];
//                    }
//                }
//            }
//        }
//        else if(i == 3){
//            if(ord == 4){
//                for (int j = 128; j < SIZE; ++j) {
//                    for (int k = 0; k < 128; ++k) {
//                        image[j][k] = image2[j][k+128];
//                    }
//                }
//            }
//            else if(ord == 3){
//                continue;
//            }
//            else if(ord == 2){
//                for (int j = 128; j < SIZE; ++j) {
//                    for (int k = 0; k < 128; ++k) {
//                        image[j][k] = image2[j-128][k+128];
//                    }
//                }
//            }
//            else if(ord == 1){
//                for (int j = 128; j < SIZE; ++j) {
//                    for (int k = 0; k < 128; ++k) {
//                        image[j][k] = image2[j-128][k];
//                    }
//                }
//            }
//        }
//        else if(i == 4){
//            if(ord == 4){
//                continue;
//            }
//            else if(ord == 3){
//                for (int j = 128; j < SIZE; ++j) {
//                    for (int k = 128; k < SIZE; ++k) {
//                        image[j][k] = image2[j][k-128];
//                    }
//                }
//            }
//            else if(ord == 2){
//                for (int j = 128; j < SIZE; ++j) {
//                    for (int k = 128; k < SIZE; ++k) {
//                        image[j][k] = image2[j-128][k];
//                    }
//                }
//            }
//            else if(ord == 1){
//                for (int j = 128; j < SIZE; ++j) {
//                    for (int k = 128; k < SIZE; ++k) {
//                        image[j][k] = image2[j-128][k-128];
//                    }
//                }
//            }
//        }
//    }
//    saveImage();
//}
//void Crop_img(){
//    loadImage();
//    unsigned char image2[SIZE][SIZE];
//    int x,y;
//    cout << "please enter the length : " << endl ;
//    cin >> x ;
//    cout << "please enter the width : " << endl ;
//    cin >> y ;
//    for(int i = 0 ; i< SIZE ; i++){
//        for(int j = 0 ; j < SIZE ; j++){
//            image2[i][j] = 255;
//        }
//    }
//    for(int i= x; i< SIZE - x ;i++){
//        for(int j = y ; j< SIZE - y;j++){
//            image2[i][j]= image[i][j];
//        }
//    }
//    char imageFileName[100];
//
//    // Get gray scale image target file name
//    cout << "Enter the target image file name: ";
//    cin >> imageFileName;
//
//    // Add to it .bmp extension and load image
//    strcat (imageFileName, ".bmp");
//    writeGSBMP(imageFileName, image2);
//}
//void Mirror_img(){
//    loadImage();
//    cout << "enter the direction of how you want to mirror your image: ";
//    string direction;
//    cin >> direction;
//    if(direction == "left"){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 127; j >= 0; --j) {
//                image[i][255-j] = image[i][j];
//            }
//        }
//        saveImage();
//    }
//    else if(direction == "right"){
//        for (int i = 0; i < SIZE; ++i) {
//            for (int j = 255; j >= 128; --j) {
//                image[i][255-j] = image[i][j];
//            }
//        }
//        saveImage();
//    }
//    else if(direction == "upper"){
//        for (int i = 0; i < 128; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image[255-i][j] = image[i][j];
//            }
//        }
//        saveImage();
//    }
//    else if(direction == "down"){
//        for (int i = 128; i < SIZE; ++i) {
//            for (int j = 0; j < SIZE; ++j) {
//                image[255-i][j] = image[i][j];
//            }
//        }
//        saveImage();
//    }
//
//}
//void Skew_img_right(){
//
//}
//void Skew_img_left(){
//
//}
int main()
{
    cout << "Welcome to our filter program.\n";
    cout << "Please choose what filter you want to apply on your image: \n";
    cout << "1-Black & White Filter \n" << "2-Invert Filter\n" << "3-Merge Filter \n" << "4-Flip Image\n" << "5-Darken and Lighten Image \n"
         << "6-Rotate Image\n" << "7-Detect Image Edges \n" << "8-Enlarge Image \n" << "9-Shrink Image\n" << "10-Mirror 1/2 Image \n"
         << "11-Shuffle Image\n" << "12-Blur Image\n" << "13-Crop Image\n" << "14-Skew Image Right \n" << "15-Skew Image Up\n";
    int num_filter;
    string cont = "yes";
    while (cont == "yes"){
        cout << "Please enter the number associated to the filter you want: ";
        cin >> num_filter;
        if(num_filter == 1){
            B_W_img();
        }
//        else if(num_filter == 2){
//            Invert_img();
//        }
//        else if(num_filter == 3){
//            Merge_img();
//        }
//        else if(num_filter == 4){
//            Flip_img();
//        }
//        else if(num_filter == 5){
//            Darken_Lighten_img();
//        }
//        else if(num_filter == 6){
//            Rotate_img();
//        }
//        else if(num_filter == 7){
//            Edges_img();
//        }
//        else if(num_filter == 8){
//            Enlarge_image();
//        }
//        else if(num_filter == 9){
//            Shrink_img();
//        }
//        else if(num_filter == 10){
//            Mirror_img();
//        }
//        else if(num_filter == 11){
//            Shuffle_img();
//        }
//        else if(num_filter == 12){
//            Blur_img();
//        }
//        else if(num_filter == 13){
//            Crop_img();
//        }
//        else if(num_filter == 14){
//
//        }
//        else if(num_filter == 15){
//
//        }
        cout << "Enter yes to continue or no to exit: ";
        cin >> cont;
    }
  return 0;
}

//_________________________________________
void loadImage () {
   char imageFileName[100];

   // Get gray scale image file name
   cout << "Enter the source image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image);
}
void loadImage1 () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Enter the source image file name you want to merge with: ";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readRGBBMP(imageFileName, image1);
}

//_________________________________________
void saveImage () {
   char imageFileName[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName;

   // Add to it .bmp extension and load image
   strcat (imageFileName, ".bmp");
   writeRGBBMP(imageFileName, image);
}
