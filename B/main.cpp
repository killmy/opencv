/*
改变图片的对比度和亮度
公式:
g(i,j) = a.f(i,j)+p
*/
#include <iostream>
#include <opencv4/opencv2/core/core.hpp>
#include <opencv4/opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat ChangePixel(const Mat& img,const double alpha,const int beta)
{
	Mat newImg=Mat::zeros(img.size(),img.type ());    // the img to be returned
	int chnnels=img.channels ();            //Get the channels of source img
	for (int x=0;x<img.rows;x++)             //iteration rows
	{
		//用指针访问
		const uchar *p=img.ptr <uchar>(x);    //由于img被声明为const，所以指针也要声明为const
		uchar *q=newImg.ptr <uchar>(x);
		int cols=img.cols*chnnels;
		for (int y=0;y<cols;y++)
		{
			q[y]=saturate_cast<uchar>(p[y]*alpha+beta);  //注意saturate_cast的使用
                        
		}
		
	}
	return newImg;
}

int main()
{
	int64 time_start=getTickCount ();
	Mat A=imread ("/home/g/learning_cpp/opencv/BLI/3.jpg",1);
	imshow ("A的图像",A);

	Mat B=ChangePixel (A,2,0);
	imshow ("B的图像",B);
	int64 time_end=getTickCount ();
	double time_take=(time_end-time_start)*1000.0/getTickFrequency ();
	cout<<"The time is "<<time_take<<"ms"<<endl;
	waitKey ();
	return 0;
}