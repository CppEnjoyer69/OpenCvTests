
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

string path = "Resources/car.jpg";
Mat img = imread(path);
Mat imgResized, mask, imgHSV;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

int main()
{
  resize(img, imgResized, Size(), 0.5, 0.5);
  cvtColor(img, imgHSV, COLOR_BGR2HSV);
  namedWindow("trackbar", (500,300));
  createTrackbar("hue min", "trackbar", &hmin, 179);
  createTrackbar("hue max", "trackbar", &hmax, 179);
  createTrackbar("sat min", "trackbar", &smin, 255);
  createTrackbar("sat max", "trackbar", &smax, 255);
  createTrackbar("val min", "trackbar", &vmin, 255);
  createTrackbar("val max", "trackbar", &vmax, 255);

  while(true)
  {
    Scalar lower(hmin, smin, vmin);
    Scalar upper(hmax, smax, vmax);
    inRange(imgHSV, lower, upper, mask);
  	imshow("car", mask);




waitKey(1);
  }





		





    return 0;
}
