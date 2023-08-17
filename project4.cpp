#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat src, dst;
	src = imread("C:/Users/admin/desktop/hehe.png");
	if (!src.data) {
		cout << "eheh" << endl;
		return -1;
	}
	dst = Mat::zeros(src.size(), src.type());
	int rows = src.rows;
	int cols = src.cols;
	float alpha = 1.2;
	float beta = 10;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (src.channels() == 3) {
				float b = src.at<Vec3b>(row, col)[0];
				float g = src.at<Vec3b>(row, col)[1];
				float r = src.at<Vec3b>(row, col)[2];

				dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(b * alpha + beta);
				dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(g * alpha + beta);
				dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(r * alpha + beta);
			}
			else {
				int gray = src.at<uchar>(row,col);
				dst.at<uchar>(row, col) = saturate_cast<uchar>(gray * alpha + beta);
			}
		}
	}

	imshow("1", src);
	imshow("2", dst);
	waitKey(0);
	return 0;
}