#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

int main() {
	Mat src = imread("C:/Users/admin/DEsktop/hehe.png");
	Mat dst;
	namedWindow("output", WINDOW_AUTOSIZE);
	imshow("output", src);
	int rows = src.rows;
	int cols = src.cols * src.channels();
	int offsetx = src.channels();
	dst = Mat::zeros(src.size(), src.type());
	/*
	for (int row = 1; row < rows - 1; row++) {
		const uchar* current = src.ptr<uchar>(row);
		const uchar* pre = src.ptr<uchar>(row - 1);
		const uchar* next = src.ptr<uchar>(row + 1);
		uchar* output = dst.ptr<uchar>(row);
		for (int col = offsetx; col < cols; col++) {
			output[col] = saturate_cast<uchar>(5 * current[col] - (current[col - offsetx] + current[col + offsetx] + pre[col] + next[col]));
		}
	}
	*/

	Mat kernel = (Mat_<char>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(src, dst, src.depth(), kernel);
	namedWindow("output hehe", WINDOW_AUTOSIZE);
	imshow("output hehe", dst);

	waitKey(0);
	return 0;
}