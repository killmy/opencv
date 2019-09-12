#include <iostream>
#include <opencv4/opencv2/opencv.hpp>

using namespace std;

int main()
{
        cv::VideoCapture capture(0);
        capture.open(0);//判断有没有开启摄像头
        if (capture.isOpened())
        {
                while (1)
                {
                        
                        cv::Mat frame;
                        capture >> frame;
                        if(frame.empty())
                                break;
                        cv::namedWindow("s");
                        cv::imshow("s",frame);
                        if(cv::waitKey(1)>=0)
                        {
                                break;
                        }

                }
        }       
        else
        {
                cout<<"error: cant find 设备"<<endl;
        }
        return 0;
}