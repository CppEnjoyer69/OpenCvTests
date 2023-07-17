
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

string path = "Resources/cards1.jpg";
int main(void)
{
	float width = 400, height = 550;

  Mat matrix,imgWarp;
	Mat img = imread(path);
  
  Point2f sourcePoints[4] = { {275,287}, {341,287}, {265,360}, {341,360}};
  Point2f destinationPoints[4] = {{0.0f, 0.0f}, {width,0.0f}, {0.0f, height}, {width, height}};
  matrix = getPerspectiveTransform(sourcePoints, destinationPoints);

   warpPerspective(img, imgWarp, matrix, Point(width, height));
  imshow("img", img);
  imshow("cardswrap", imgWarp);
  
		





		waitKey(0);





    return 0;
}
