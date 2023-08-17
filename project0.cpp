#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int agrs, char** argv) {
	Mat src = imread("C:/Users/admin/Desktop/hehe.png");

	if (src.empty()) {
		cout << "hb" << endl;
		return -1;
	}

	namedWindow("test", WINDOW_AUTOSIZE);
	imshow("test", src);

	Mat lhr;
	namedWindow("nmsl", WINDOW_AUTOSIZE);

	cvtColor(src, lhr, COLOR_BGR2GRAY);

	imshow("nmsl", lhr);

	waitKey(0);
	return 0;
}