/*#include <iostream>
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
*/
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>


using namespace cv;
using namespace std;

void scalePartAverage(const Mat &src, Mat &dst, double xRatio, double yRatio);
void average(const Mat &img, Point_<int> a, Point_<int> b, Vec3b &p);
int main()
{
        Mat src;
        Mat dst;
        Mat dst2;
        double xr = 0.5;
        double yr = 0.5;
        src = imread("/home/g/learning_cpp/opencv/localmean/1.jpg");
        namedWindow("src");
        imshow("src",src);
        scalePartAverage(src,dst,xr,yr);
        //src = imread("/home/g/learning_cpp/opencv/localmean/1.jpg");
        scalePartAverage(dst,dst2,xr,yr);
        namedWindow("dst");
        imshow("dst",dst);

        namedWindow("dst2");
        imshow("dst2",dst2);
        waitKey(0);
        return 0;
}


/*
src:原图
dst:转换后的目标图;
xRatio：缩放比x
yRatio: 缩放比y
*/
void scalePartAverage(const Mat &src, Mat &dst, double xRatio, double yRatio)
{
        int rows = static_cast<int>(src.rows * xRatio);//缩放后的图片高，行
        int cols = static_cast<int>(src.cols * yRatio);//缩放后图片的宽，列
        //static_cast强制类型转换

        dst.create(rows,cols,src.type());//创建目标图片
        int lastRow = 0;
        int lastCol = 0;
        Vec3b * p;//向量
        for (int i = 0; i < rows; i++) 
        {
                p = dst.ptr<Vec3b>(i);//
                int row = static_cast<int>((i + 1) / xRatio + 0.5) - 1;//对应的未缩放图片行
                for (int j = 0; j < cols; j++) 
                {
                        int col = static_cast<int>((j + 1) / yRatio + 0.5) - 1;//对应未缩减图片列

                        Vec3b pix;
                        average(src, Point_<int>(lastRow, lastCol), Point_<int>(row, col), pix);
                        p[j] = pix;

            lastCol = col + 1; //下一个子块左上角的列坐标，行坐标不变
        }
        lastCol = 0; //子块的左上角列坐标，从0开始
        lastRow = row + 1; //子块的左上角行坐标
        }
}
void average(const Mat &img, Point_<int> a, Point_<int> b, Vec3b &p)
{

    const Vec3b *pix;
    Vec3i temp;
    for (int i = a.x; i <= b.x; i++){
        pix = img.ptr<Vec3b>(i);
        for (int j = a.y; j <= b.y; j++){
            temp[0] += pix[j][0];
            temp[1] += pix[j][1];
            temp[2] += pix[j][2];
        }
    }

    int count = (b.x - a.x + 1) * (b.y - a.y + 1);
    p[0] = temp[0] / count;
    p[1] = temp[1] / count;
    p[2] = temp[2] / count;
}