#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main()
{
	string path = "Resources/lelo2.jpg";
	Mat img = imread(path);
	Mat imgBlur, imgCanny,imgDil,imgErode;

	GaussianBlur(img, imgBlur, Size(5, 3), 0, 7);
	Canny(imgBlur, imgCanny, 50, 120);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);

	imshow("Image", img);
	imshow("Image Blurred", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilated", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
}