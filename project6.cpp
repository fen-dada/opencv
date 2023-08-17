#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
	Mat src, dst;
	src = imread("C:/Users/admin/desktop/hehe.png");
	if (!src.data) {
		cout << "hehe" << endl;
		return -1;

	}

	//medianBlur(src, dst, 3);//��㴦��
	Mat res;
	bilateralFilter(src, dst, 15, 150, 3);//Ч������
	//GaussianBlur(src, res, Size(15, 15), 3, 3);
	Mat kernel = (Mat_<int>(3,3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
	filter2D(dst, res, -1, kernel);
	imshow("1", src);
	imshow("2", dst);
	imshow("3", res);
	waitKey(0);
	return 0;
}