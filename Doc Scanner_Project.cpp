#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include<iostream>

using namespace std;
using namespace cv;

Mat imgoriginal, imgGray, imgBlur, imgCanny,imgthres,imgDil, imgErode;
vector<Point>initialPoints;

Mat preProcessing(Mat img)
{
	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(5, 3), 0, 7);
	Canny(imgBlur, imgCanny, 50, 120);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(1, 1));

	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel);
	return imgErode;
}
  vector<Point> getContours(Mat image) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());

	vector<Point> biggest;
	int maxArea = 0;

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		//cout << area << endl;

		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

			if (area > maxArea && conPoly[i].size()==4) {

				biggest = {conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3] };
				maxArea = area;
			}

			//drawContours(imgoriginal, conPoly, i, Scalar(255, 0, 255), 2);
			//rectangle(imgoriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
		}
	}
	return biggest;
}

  void drawPoints(vector<Point>points, Scalar color) 
  {
	  for (int i = 0; i < points.size(); i++)
	  {
		  circle(imgoriginal, points[i], 30, color, FILLED);
		  putText(imgoriginal, to_string(i), points[i], FONT_HERSHEY_PLAIN, 5, color, 5);

	  }
  }


void main()
{
	string path = "Resources/Documents.jpg";
	Mat imgoriginal = imread(path);
	resize(imgoriginal, imgoriginal, Size(), 0.40,0.40);
	//Preprocessing//
	imgthres = preProcessing(imgoriginal);

	// Find Biggest Countour in the Image//
	initialPoints=getContours(imgthres);

	drawPoints(initialPoints, Scalar(0, 0, 255));

	imshow("Original Image", imgoriginal);
	imshow("Image", imgthres);
	waitKey(0);
}
