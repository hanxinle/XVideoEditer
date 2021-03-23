#include "XVideoThread.h"
#include "XFilter.h"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/core.hpp>
#include <iostream>
using namespace std;
using namespace cv;

static VideoCapture cap1;
// isExit 解决程序结束时，线程运行时报错的问题
static bool isExit = false;
void XVideoThread::run() {
    Mat mat1;
    for (;;) {
        mutex.lock();
        if (isExit) {
            mutex.unlock();
            break;
        }
        //判断视频是否打开
        if (!cap1.isOpened()) {
            mutex.unlock();
            msleep(5);
            continue;
        }
        //读取一帧视频，解码并颜色转换
        if (!cap1.read(mat1) || mat1.empty()) {
            mutex.unlock();
            msleep(5);
            continue;
        }
        //显示图像
        ViewImage1(mat1);

        Mat dst = XFilter::Get()->Filter(mat1, Mat());
        // 显示图像

        ViewImage2(dst);
        // ViewDes(dst);
        msleep(40);
        mutex.unlock();
    }
}

bool XVideoThread::Open(std::string file) {
    cout <<"open :"<< file << endl;
    mutex.lock();
    bool re = cap1.open(file);
    mutex.unlock();
    cout << re << endl;
    return re;
}

XVideoThread::XVideoThread() {
    // Qthread 编程的坑，不了解可能就没有
    start();
}
XVideoThread::~XVideoThread() {
    mutex.lock();
    isExit = true;
    mutex.unlock();
    wait();
}
