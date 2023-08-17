#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/admin/DEsktop/hehe.png");
	Mat gray;
	if (src.empty()) {
		cout << "hehe" << endl;
		return -1;

	}
	//namedWindow("origin", WINDOW_AUTOSIZE);
	imshow("origin", src);

	cvtColor(src, gray, COLOR_BGR2GRAY);
	
	int rows = gray.rows;
	int cols = gray.cols;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			int val = gray.at<uchar>(row, col);
			gray.at<uchar>(row, col) = 255 - val;
		}
	}
	//imshow("hehe", gray);
	
	

	Mat dst;
	dst.create(src.size(), src.type());
	//int dst_rows = src.rows;
	//int dst_cols = src.cols;
	rows = src.rows;
	cols = src.cols;
	int nc = src.channels();
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (nc == 1) {
				int val = src.at<uchar>(row, col);
				dst.at<uchar>(row, col) = 255 - val;
			}
			else if(nc == 3){
				int b = src.at<Vec3b>(row, col)[0];
				int g = src.at<Vec3b>(row, col)[1];
				int r = src.at<Vec3b>(row, col)[2];
				dst.at<Vec3b>(row, col)[0] = 255 - b;
				dst.at<Vec3b>(row, col)[1] = 255 - g;
				dst.at<Vec3b>(row, col)[2] = 255 - r;

				gray.at<uchar>(row, col) = max(r, max(g, b));
			}
		}
	}
	//bitwise_not(src, dst);

	imshow("lhr", dst);
	imshow("hh", gray);

	waitKey(0);
	return 0;
}