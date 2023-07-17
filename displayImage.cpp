
#include <opencv2/opencv.hpp>
#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

string path = "Resources/";
int main(void)
{
	VideoCapture cap(0);
	Mat img, imgBlur, cannyImg, imgDilation;

	while(true)
	{
		cap.read(img);
		GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
    Canny(imgBlur, cannyImg, 20, 40);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5));
    dilate(cannyImg, imgDilation, kernel);
		imshow("WebcamImg", imgDilation);
		waitKey(1);
	}





    return 0;
}
