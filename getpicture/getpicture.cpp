#include <opencv4/opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
        Mat src_image = imread("/home/g/learning_cpp/opencv/getpicture/1.jpg");
        imshow("原始图片",src_image);
        waitKey(0);
}