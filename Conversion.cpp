#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
/////////////////////// Webcam//////////////////////////
void main()
{
	string path = "Resources/lelo2.jpg";
	Mat img = imread(path);
	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	imshow("IMAGE", img);
	imshow("IMAGE in GRAY", imgGray);
	waitKey(0);
}