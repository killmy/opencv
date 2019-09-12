//srcX=dstX* (srcWidth/dstWidth) ,
//srcY = dstY * (srcHeight/dstHeight)
//简单的邻近插值算法

//利用周边的4个点就是双线性插值
//f(i+u,j+v) = (1-u)(1-v)f(i,j) + (1-u)vf(i,j+1) + u(1-v)f(i+1,j) + uvf(i+1,j+1) 

/*
中心对齐(OpenCV也是如此)：
SrcX=(dstX+0.5)* (srcWidth/dstWidth) -0.5
SrcY=(dstY+0.5) * (srcHeight/dstHeight)-0.5
改进
*/
#include <opencv4/opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main()
{
        Mat matSrc;
        Mat dataDst;
        matSrc = imread("/home/g/learning_cpp/opencv/BLI/3.jpg");
        imshow("matsrc",matSrc);
        int rows = static_cast<int>(matSrc.rows*2);
        int cols = static_cast<int>(matSrc.cols*2);
        dataDst.create(rows,cols,matSrc.type());

        resize(matSrc,dataDst,dataDst.size(),0,0,1);
        
        imshow("data",dataDst);

        waitKey(0);
        imwrite("4.jpg",dataDst);
        return 0;
        
}