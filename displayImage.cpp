
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
	Mat img, imgResized;
  
	while(true)
	{
		cap.read(img);
    
    resize(img, imgResized, Size(), 0.5, 0.5);
		imshow("WebcamImg", imgResized);




		waitKey(1);
	}





    return 0;
}
