#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat src;
	src = imread("C:/Users/admin/desktop/hehe.png");
	if (!src.data) {
		cout << "hehe" << endl;
		return -1;
	}

	return 0;
}