 
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

#define BLUE Scalar(100.0, 0.0, 0.0)
#define RED Scalar(0.0, 0.0, 100.0)

void changeColor(Mat, int, int);
void findPenguins(vector<Point>);
void usage();

int main(int argc, char** argv)
{
        string filename;
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

        Mat gs = Mat();
        Mat blurred = Mat();
        Mat thresh = Mat();

        //https://www.pyimagesearch.com/2016/02/08/opencv-shape-detection/
        //Convert to Grayscale
        cvtColor(image, gs, CV_BGR2GRAY);
        //Blur
        GaussianBlur(gs, blurred, Size(5, 5), 0);
        //Threshold
        threshold(blurred, thresh, 252, 255, CV_THRESH_BINARY);

        int flags = WINDOW_NORMAL;


        // Penguin 1: (393, 744)
        // Penguin 2: (801, 459)
        // Penguin 3: (1017, 810)
        // Penguin 4: (1626, 639)

        vector<vector<Point>> contours;

        findContours(thresh, contours, CV_RETR_LIST, CV_CHAIN_APPROX_SIMPLE);
        
        changeColor(image, 392, 744);
        changeColor(image, 801, 459);
        changeColor(image, 1017, 810);
        changeColor(image, 1626, 639);

        drawContours(image, contours, -1, RED, 5);

        imwrite("notblue" + filename, image);

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

void findPenguins(vector<Point> penguins)
{
        // TODO
}

void usage()
{
        cout << "Usage: webcam image-file" << endl;
}
