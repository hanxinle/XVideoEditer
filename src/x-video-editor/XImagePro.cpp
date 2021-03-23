#include "XImagePro.h"
#include "opencv2/imgproc.hpp"
using namespace cv;
void XImagePro::Set(cv::Mat mat1, cv::Mat mat2) {
    if (mat1.empty()) return;
    this->src1 = mat1;
    this->src2 = mat2;
    this->src1.copyTo(des);
}
// 设置亮度和对比度
// 亮度 0-100,对比度 0-3.0
void XImagePro::Gain(const double bright, const double contract) {
    if (des.empty()) return;
    des.convertTo(des, -1, contract, bright);
}

//图像旋转
void XImagePro::Rotate90() {
    if (des.empty())return;
    rotate(des, des, ROTATE_90_CLOCKWISE);
}
void XImagePro::Rotate180() {
    if (des.empty())return;
    rotate(des, des, ROTATE_180);
}
void XImagePro::Rotate270() {
    if (des.empty())return;
    rotate(des, des, ROTATE_90_COUNTERCLOCKWISE);
}


// 左右镜像
void XImagePro::FlipX() {
    if (des.empty())return;
    flip(des, des, 0);
}

// 上下镜像
void XImagePro::FlipY() {
    if (des.empty())return;
    flip(des, des, 1);
}

// 左右上下
void XImagePro::FlipXY() {
    if (des.empty())return;
    flip(des, des, -1);
}


void XImagePro::Resize(int width, int height) {
    if (des.empty())return;
    resize(des,des,Size(width,height));
}


XImagePro::XImagePro() { }


XImagePro::~XImagePro() { }
