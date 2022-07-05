#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

VideoCapture cap(0);
Mat img;

Mat imgHsv, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

void main()
{

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackbars", &hmax, 179);
	createTrackbar("Saturation Min", "Trackbars", &smin, 255);
	createTrackbar("Saturation Max", "Trackbars", &smax, 255);
	createTrackbar("Value Min", "Trackbars", &vmin, 255);
	createTrackbar("Value Max", "Trackbars", &vmax, 255);

	
	while (true)
	{
		cap.read(img);

		cvtColor(img, imgHsv, COLOR_BGR2HSV);
		
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);

		inRange(imgHsv, lower, upper, mask);
		cout << hmin << " ," << smin << " ," << vmin << " ," << hmax << " ," << smax << " ," << vmax << endl;

		imshow("Image", img);
		imshow("Mask", mask);
		waitKey(1);
	}
}