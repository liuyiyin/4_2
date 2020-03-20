// 4_2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("D:\\coin.png", 0);
	cv::Mat src;
	cv::Mat labelMat;
	cv::Mat statsMat;
	cv::Mat centrMat;

	threshold(srcMat, src, 100, 255, THRESH_BINARY);

	int nComp = cv::connectedComponentsWithStats(src, labelMat, statsMat, centrMat, 8, CV_32S);

	for (int i = 1; i < nComp; i++)
	{
		Rect bndbox;
		bndbox.x = statsMat.at<int>(i, 0);
		bndbox.y = statsMat.at<int>(i, 1);
		bndbox.width = statsMat.at<int>(i, 2);
		bndbox.height = statsMat.at<int>(i, 3);
		rectangle(src, bndbox, CV_RGB(255, 255, 255), 1, 8, 0);
	}

	cout << "Ӳ�Ҹ�����" << nComp - 1 << endl;
	imshow("��ͨ����", src);
	waitKey(0);
	return 0;
}

