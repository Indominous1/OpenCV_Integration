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
	Mat imgResize;
	//cout << img.size() << endl;                    //used to find the size of the image we are using in the code//

	resize(img, imgResize, Size(), 0.5, 0.5);
	imshow("Image", img);
	imshow("Image Resized", imgResize);
	waitKey(0);
}