#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main()
{
	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));
	circle(img, Point(256, 256), 155, Scalar(0,69, 255), FILLED);
	rectangle(img, Point(130,220),Point(382,282), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 292), Point(382,292), Scalar(255, 255, 255), 2);
	putText(img, "Indominus Project", Point(133, 262), FONT_HERSHEY_TRIPLEX, 0.75, Scalar(0, 0, 0), 2);
	imshow("image", img);
	waitKey(0);
}
