#include "XVideoThread.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

// 1号视频源
static VideoCapture cap1;

void XVideoThread::run() {
    Mat mat1;
    // 判断视频是否打开
    for (;;) {
        //mutex.lock();
        if (!cap1.isOpened()) {
            //mutex.lock();
            cerr << "!cap1.isOpened())" << endl;
            msleep(5);
            continue;
        }
        // 读取一帧视频，解码并作颜色转换
        if (!cap1.read(mat1) || mat1.empty()) {
            //mutex.unlock();
            cerr << "!cap1.read(mat1) || mat1.empty()" << endl;
            msleep(5);
            continue;
        }

        //显示函数
        namedWindow("cap1");
        imshow("cap1", mat1);
        cout << "signal ViewImage(mat1)" << endl;
        ViewImage1(mat1);

        //mutex.unlock();
        msleep(40);
    }

}


bool XVideoThread::Open(const std::string file) {
    cap1.open(file);
    //mutex.lock();
    if (!cap1.isOpened()) {
        //mutex.unlock();
        cout <<"XVideoThread::Open(file) error" << endl;
        return false;
    }
    //mutex.unlock();
    return true;
}

