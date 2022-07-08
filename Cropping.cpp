#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

void main()
{
	string path = "Resources/ImageCrop.jpg";
	Mat img = imread(path);
	Mat imgCrop;

	Rect roi(55,20, 330, 400);
	imgCrop = img(roi);

		imshow("Image", img);
		imshow("Cropped Image", imgCrop);
		waitKey(0);
}