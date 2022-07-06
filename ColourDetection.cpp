#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat imgHsv, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;
void main()
{
	string path = "Resources/ColourShapes.jpg";
	Mat img = imread(path);
	cvtColor(img, imgHsv, COLOR_BGR2HSV);

	namedWindow("Trackbars", (640, 200));
	createTrackbar("Hue Min", "Trackbars",&hmin,179);
	createTrackbar("Hue Max", "Trackbars",&hmax,179);
	createTrackbar("Saturation Min", "Trackbars",&smin,255);
	createTrackbar("Saturation Max", "Trackbars", &smax,255);
	createTrackbar("Value Min","Trackbars",&vmin,255);
	createTrackbar("Value Max","Trackbars",&vmax,255);

	while (true)
	{
		Scalar lower(hmin, smin, vmin);
		Scalar upper(hmax, smax, vmax);
		inRange(imgHsv, lower, upper, mask);

		imshow("Image", img);
		imshow("Image HSV", imgHsv);
		imshow("Image Mask", mask);
		waitKey(1);
	}
	
}