 
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;

#define BLUE Scalar(100.0, 0.0, 0.0)

void changeColor(Mat, int, int);

int main(int argc, char** argv)
{
  Mat image = imread("./penguins.jpg");

  if(image.empty())
    {
      cout << "no file" << endl;
      return -1;
    }

  int flags = WINDOW_NORMAL;

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
  // Penguin 1: (393, 744)
  // Penguin 2: (801, 459)
  // Penguin 3: (1017, 810)
  // Penguin 4: (1626, 639)
  Point seed = Point(x, y);
  floodFill(image, seed, BLUE, NULL,
            Scalar(7.0, 7.0, 7.0, 0.0),
            Scalar(5.0, 5.0, 5.0, 0.0),
            4);
}
