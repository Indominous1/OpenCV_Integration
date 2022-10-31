#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

float w = 300, h = 350;
Mat matrix, imgWarp;
void main()
{
	string path = "Resources/CardsW.jpg";
	Mat img = imread(path);
	Point2f src[4] = { {385,59},{662,105},{319,449},{595,498} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	line(img, Point(385, 59), Point(319, 449), Scalar(0, 0, 255), 2);
	line(img, Point(319, 449), Point(595, 498), Scalar(0, 0, 255), 2);
	line(img, Point(595, 498), Point(662, 105), Scalar(0, 0, 255), 2);
	line(img, Point(662, 105), Point(385, 59), Scalar(0, 0, 255), 2);

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 10, Scalar(0, 0, 200),FILLED);
	}
	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);
}


