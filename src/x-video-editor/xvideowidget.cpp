#include "xvideowidget.h"
#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include <QPainter>

#include <iostream>
using namespace std;
using namespace cv;




void XVideoWidget::SetImage(cv::Mat mat) {
    QImage::Format fmt = QImage::Format_RGB888;
    int pixSize = 3;

    //灰度图
    if (mat.type() == CV_8UC1) {
        fmt = QImage::Format_Grayscale8;
        pixSize = 1;
    }
    if (img.isNull() || img.format() != fmt) {
        delete img.bits();
        uchar *buf = new uchar[width()*height() * pixSize];
        img = QImage(buf, width(), height(), fmt);
    }
    Mat des;
    //设置图像大小
    cv::resize(mat, des, Size(img.size().width(), img.size().height()));

    //设置图像颜色格式
    if (pixSize>1)
        cv::cvtColor(des, des, COLOR_BGR2RGB);

    //复制内存空间
    memcpy(img.bits(), des.data, des.cols*des.rows*des.elemSize());
    update();    // 一开始的版本，颜色错乱
    //if (img.isNull()) {
    //    uchar *buf = new uchar[width()*height() * 3];
    //    img = QImage(buf, width(), height(), QImage::Format_RGB888);
    //}
    //Mat des;
    ////设置图像大小
    //cv::resize(mat, des, Size(img.size().width(), img.size().height()));
    ////设置图像颜色格式
    ////cv::cvtColor(des, des, COLOR_BGR2RGB);

    ////复制内存空间
    //memcpy(img.bits(), des.data, des.cols*des.rows*des.elemSize());
    //update();
}

void XVideoWidget::paintEvent(QPaintEvent * e) {
    QPainter p;
    p.begin(this);
    p.drawImage(QPoint(0, 0), img);
    p.end();
    //Mat src = imread("1.png");
    //cvtColor(src, src, COLOR_BGR2RGB);
    //QImage img(src.data, src.cols, src.rows, QImage::Format_RGB888);
    //QPainter p;
    //p.begin(this);
    //p.drawImage(QPoint(0, 0), img);
}

XVideoWidget::XVideoWidget(QWidget * w) :QOpenGLWidget(w) { }

XVideoWidget::~XVideoWidget() { }


