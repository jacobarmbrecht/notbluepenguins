 
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include "list.h"

using namespace cv;
using namespace std;

#define BLUE Scalar(100.0, 0.0, 0.0)

void changeColor(Mat, int, int);
void findPenguins(llist**);
void usage();

int main(int argc, char** argv)
{
        char* filename;
        if (argc < 2)
        {
                usage();
                return 0;
        }
        else
        {
                filename = argv[1];
        }
        
        Mat image = imread(filename);
  
        if(image.empty())
        {
                cout << "I can't find " << filename << endl;
                return -1;
        }

        int flags = WINDOW_NORMAL;


        // Penguin 1: (393, 744)
        // Penguin 2: (801, 459)
        // Penguin 3: (1017, 810)
        // Penguin 4: (1626, 639)
        
        changeColor(image, 392, 744);
        changeColor(image, 801, 459);
        changeColor(image, 1017, 810);
        changeColor(image, 1626, 639);

        String windowName = "It's been an honor Mrs. Obama";

        namedWindow(windowName,flags);

        imshow(windowName, image);

        moveWindow(windowName,0,0);
        resizeWindow(windowName,10000,100000);

        waitKey(0);
        destroyWindow(windowName);

        return 0;
}

void changeColor(Mat image, int x, int y)
{
        Point seed = Point(x, y);
        floodFill(image, seed, BLUE, NULL,
                  Scalar(7.0, 7.0, 7.0, 0.0),
                  Scalar(5.0, 5.0, 5.0, 0.0),
                  4);
}

void findPenguins(llist* penguins)
{
        // TODO
}

void usage()
{
        cout << "Usage: webcam image-file" << endl;
}
