#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int main() {
	Mat src1, src2, dst;
	src1 = imread("C:/Users/admin/DEsktop/hehe.png");
	src2 = imread("C:/Users/admin/DEsktop/hehe.png");
	double alpha = 0.5;
	if (!src1.data) {
		cout << "hehe" << endl;
		return -1;
	}
	if (!src2.data) {
		cout << "haha" << endl;
		return -1;
	}
	if (src1.rows == src2.rows && src1.cols == src2.cols && src1.type() == src2.type()) {
		addWeighted(src1, alpha, src2, 1.0 - alpha, 0.0, dst);
		//add(src1, src2, dst, Mat());
		//multiply(src1, src2, dst, 1.0);
		imshow("1", src1);
		imshow("2",src2);
		imshow("hehe", dst);
	}
	waitKey(0);
	return 0;
}