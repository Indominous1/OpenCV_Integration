#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
void main()
{
	string path = "Resources/Video.mp4";
	VideoCapture cap(path);
	Mat Img;
	while (true)
	{
		cap.read(Img);
		imshow("Image", Img);
		waitKey(22);
	}
}