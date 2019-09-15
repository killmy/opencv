#include <opencv4/opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

#define window_name "二值化"；
struct  const_trackbar
{
        int Max_value ;//划条最大值
        int Min_value ;//划条最小位置
        int position_variable;//划条的位置

}const_value ;
Mat src;

void onChangeTrackBar(int pos, void *data)
{
	//强制类型转换
	Mat srcImage = *(cv::Mat*)(data);
	Mat dstImage;
	//根据拖动条的值对传入图像进行二值化
	threshold(srcImage, dstImage, pos, 255, 0);
	imshow("threshold", dstImage);
}
int main()
{
        const_value ={255,0,0};
        src = imread("/home/g/learning_cpp/opencv/BLI/3.jpg",0);
        namedWindow("threshold");
        imshow("threshold",src);
        createTrackbar("pos","threshold",0,255,onChangeTrackBar,&src);
        waitKey(0);
}
