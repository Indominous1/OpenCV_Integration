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
	Mat imgBlur;
	GaussianBlur(img, imgBlur, Size(5, 3),0,7);
	imshow("Image", img);
	imshow("Blurred Image", imgBlur);
	waitKey(0);
}