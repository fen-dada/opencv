#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
Mat src = imread("C:/Users/admin/desktop/hehe.png");
void heheline() {
	Point p1 = Point(10, 20);
	Point p2 = Point(300, 300);
	Scalar color = Scalar(0, 0, 255);
	line(src, p1, p2, color);
}

void heherec() {
	Scalar color = Scalar(255, 0, 0);
	Rect rect = Rect(100, 200, 300, 300);
	rectangle(src, rect, color);
}

void heheelli() {
	Scalar color = Scalar(0, 255, 255);
	ellipse(src, Point(src.cols / 2, src.rows / 2), Point(src.cols / 4, src.rows / 8), 90, 0, 360, color, 2, 8);
}

void hehecir() {
	Scalar color = Scalar(255, 255, 255);
	circle(src, Point(200, 200), 150, color, 2, 8);
}
void hehepolygon() {
	Point pts[1][5];
	pts[0][0] = Point(100, 100);
	pts[0][1] = Point(100, 200);
	pts[0][2] = Point(200, 200); 
	pts[0][3] = Point(200, 100);
	pts[0][4] = Point(100, 100);

	const Point* ppts[] = { pts[0] };

	const int npt[] = { 5 };
	Scalar color = Scalar(0, 255, 0);
	fillPoly(src, ppts, npt, 1, color);
}

void lhr() {
	RNG rng(123456);
	Mat eheh;
	eheh = Mat::zeros(src.size(), src.type());
	Scalar color = Scalar(255, 0, 255);
	for (int i = 0; i < 10000; i++) {
		Point p1 = Point(rng.uniform(0, src.cols), rng.uniform(0, src.rows));
		Point p2 = Point(rng.uniform(0, src.cols), rng.uniform(0, src.rows));
		line(eheh, p1, p2, color);
		if (waitKey(50) > 0) break;
		imshow("hehe", eheh);
		waitKey(500);
	}
}


int main() {

	if (!src.data) {
		cout << "hehe" << endl;
		return -1;
	}
	heheline();
	heherec();
	heheelli();
	hehecir();
	hehepolygon();
	lhr();
	imshow("1", src);

	waitKey(0);
	return 0;
}