// g++ dat2png.cpp -lboost_filesystem -lX11 -Wall -pedantic
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <boost/filesystem.hpp>
#include <CImg.h>
using namespace std;
using namespace cimg_library;

// used for the game main loop
unsigned char pal1[]={
    0,0,0, 63,63,63, 54,54,54, 50,50,50, 42,42,42, 37,37,37,
    25,25,25, 63,0,0, 54,0,0, 46,0,0, 37,0,0, 63,63,0,
    63,42,0, 0,63,63, 29,46,63, 33,0,33, 33,63,33, 0,63,0,
    0,46,0, 0,33,0, 0,33,63, 0,25,58, 0,16,50, 0,8,46,
    0,4,37, 0,0,33, 63,37,33, 46,21,21, 33,16,0, 29,12,0,
    25,8,0, 21,4,0, 0,0,0, 31,31,31, 27,27,27, 25,25,25,
    21,21,21, 18,18,18, 12,12,12, 31,0,0, 27,0,0, 23,0,0,
    18,0,0, 31,31,0, 31,21,0, 0,31,31, 14,23,31, 16,0,16,
    16,31,16, 0,31,0, 0,23,0, 0,16,0, 0,16,31, 0,12,29,
    0,8,25, 0,4,23, 0,2,18, 0,0,16, 31,18,16, 23,10,10,
    16,8,0, 14,6,0, 12,4,0, 10,2,0};

// used for the logo
unsigned char pal2[]={
    0,0,0, 63,63,63, 54,54,54, 46,46,46, 33,33,33, 25,25,25,
    16,16,16, 63,33,0, 63,42,0, 63,50,0, 63,58,0, 63,63,0,
    63,63,12, 63,63,29, 63,63,25, 63,63,63, 0,33,63, 0,29,63,
    0,25,63, 0,25,58, 0,21,58, 0,16,54, 0,16,54, 0,12,50,
    0,12,50, 0,8,46, 0,4,46, 0,4,42, 0,4,0, 0,0,37,
    0,0,37, 0,0,33, 0,0,0, 31,31,31, 27,27,27, 23,23,23,
    16,16,16, 12,12,12, 8,8,8, 31,16,0, 31,21,0, 31,25,0,
    31,29,0, 31,31,0, 31,31,6, 31,31,14, 31,31,12, 31,31,31,
    0,16,31, 0,14,31, 0,12,31, 0,12,29, 0,10,29, 0,8,27,
    0,8,27, 0,6,25, 0,6,25, 0,4,23, 0,2,23, 0,2,21,
    0,2,0, 0,0,18, 0,0,18, 0,0,16};

// used for the title
unsigned char pal3[]={
    0,0,0, 63,63,63, 54,54,54, 0,33,63, 0,29,63, 0,25,63,
    0,25,58, 63,0,0, 54,0,0, 46,0,0, 37,0,0, 63,63,0,
    63,54,0, 63,46,0, 63,37,0, 37,37,37, 0,63,0, 0,54,0,
    0,46,0, 0,37,0, 0,21,58, 0,16,54, 0,16,54, 0,12,50,
    0,12,50, 0,8,46, 0,4,46, 0,4,42, 0,0,42, 0,0,37,
    0,0,37, 0,0,33, 0,0,0, 31,31,31, 27,27,27, 0,16,31,
    0,14,31, 0,12,31, 0,12,29, 31,0,0, 27,0,0, 23,0,0,
    18,0,0, 31,31,0, 31,27,0, 31,23,0, 31,18,0, 18,18,18,
    0,31,0, 0,27,0, 0,23,0, 0,18,0, 0,10,29, 0,8,27,
    0,8,27, 0,6,25, 0,6,25, 0,4,23, 0,2,23, 0,2,21,
    0,0,21, 0,0,18, 0,0,18, 0,0,16};

void convert_screen(const char *inputfilename, const char *outputfilename, int palette) {
    const int width = 320;
    const int height = 200;

    const int filesize = boost::filesystem::file_size(inputfilename);

    unsigned char *pal;
    if(palette==1) pal = pal1;
    else if(palette==2) pal = pal2;
    else pal = pal3;

    char *data = new char[filesize];
    ifstream input(inputfilename, ios::in | ios::binary);
    input.read(data, filesize);
    input.close();

    CImg<unsigned char> image(width, height, 1, 3);
    for(int i = 0; i < width; i++) {
        for(int j = 0; j < height; j++) {
            int indx = data[i + (j*width)];
            int offset = indx * 3;
            unsigned int tmp = pal[offset]; tmp = ((tmp << 2) | ( tmp >> 4 ));
            image(i, j, 0, 0) = tmp;
            tmp = pal[offset+1]; tmp = ((tmp << 2) | ( tmp >> 4 ));
            image(i, j, 0, 1) = tmp;
            tmp = pal[offset+2]; tmp = ((tmp << 2) | ( tmp >> 4 ));
            image(i, j, 0, 2) = tmp;
            //cout << "x" << i << " y" << j << endl;
        }
    }

    image.save_png(outputfilename);

    delete[] data;
}

void convert_tiles(const char *inputfilename, int palette) {

    const int filesize = boost::filesystem::file_size(inputfilename);

    unsigned char *pal;
    if(palette==1) pal = pal1;
    else if(palette==2) pal = pal2;
    else pal = pal3;

    char *data = new char[filesize];
    ifstream input(inputfilename, ios::in | ios::binary);
    input.read(data, filesize);
    input.close();

    int pic = 0;
    int counter = 0;

    while(counter < filesize) {
        unsigned char width = data[counter]; counter++;
        unsigned char height = data[counter]; counter++;

        CImg<unsigned char> image(width, height, 1, 3);
        for(int i = 0; i < width; i++) {
            for(int j = 0; j < height; j++) {
                int indx = data[counter + i + (j*width)];
                int offset = indx * 3;
                unsigned int tmp = pal[offset]; tmp = ((tmp << 2) | ( tmp >> 4 ));
                image(i, j, 0, 0) = tmp;
                tmp = pal[offset+1]; tmp = ((tmp << 2) | ( tmp >> 4 ));
                image(i, j, 0, 1) = tmp;
                tmp = pal[offset+2]; tmp = ((tmp << 2) | ( tmp >> 4 ));
                image(i, j, 0, 2) = tmp;
                //cout << "x" << i << " y" << j << endl;
            }
        }

        ostringstream strnum;
        strnum << setw(3) << setfill('0') << pic; // pad to 3 nums

        image.save_png((strnum.str() + ".png").c_str());
        pic++;
        counter += width*height;
    }

    delete[] data;
}

int main() {
    //convert_screen("logo.dat", "logo.png", 2);
    //convert_screen("title.dat", "title.png", 3);
    //convert_tiles("tiles1.dat", 1);
    //convert_tiles("tiles2.dat", 1);
    //convert_tiles("tiles3.dat", 1);
    convert_tiles("tiles.dat", 1);
    return 0;
}
