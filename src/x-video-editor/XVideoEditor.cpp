#include "XVideoEditor.h"
#include "XVideoThread.h"
#include "xvideowidget.h"
#include "XFilter.h"

#include <QFileDialog>
#include <string>
#include <QMessageBox>
#include <iostream>
#include <opencv2/core.hpp>
using namespace std;
XVideoEditor::XVideoEditor(QWidget *parent)
    : QWidget(parent) {
    ui.setupUi(this);
    qRegisterMetaType<cv::Mat>("cv::Mat");
    QObject::connect(XVideoThread::Get(),
                     SIGNAL(ViewImage1(cv::Mat)),
                     ui.src,
                     SLOT(SetImage(cv::Mat)));
    QObject::connect(XVideoThread::Get(),
                     SIGNAL(ViewImage2(cv::Mat)),
                     ui.dst,
                     SLOT(SetImage(cv::Mat)));

    QObject::connect(XVideoThread::Get(),
                     SIGNAL(ViewDes(cv::Mat)),
                     ui.dst,
                     SLOT(SetImage(cv::Mat)));
}


void XVideoEditor::Open() {
    QString name = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("请选择视频文件"));
    if (name.isEmpty()) return;
    string file = name.toLocal8Bit().data();
    //QMessageBox::information (this, "", name);
    int re = XVideoThread::Get()->Open(file);
    if (!re) {
        QMessageBox::information(this, "", "XVideoThread::Get ()->Open (file)) failed.");
    }
}
void XVideoEditor::Set() {
    XFilter::Get()->Clear();

    // 调整视频尺寸
    if (ui.width->value() > 0 &&
        ui.height->value() > 0) {
        XFilter::Get()->Add(XTask{XTASK_RESIZE,
                            {(double) ui.width->value(),
                            (double) ui.height->value()}
                            });
    }

    if (ui.bright->value() > 0 &&
        ui.contact->value() > 0) {
        XFilter::Get()->Add(XTask{XTASK_GAIN,
                            {(double) ui.bright->value(),(double) ui.contact->value()}
                            });
    }
    // 图像旋转
    if (ui.rotateBox->currentIndex() == 1) {
        XFilter::Get()->Add(XTask{XTASK_ROTATE90});
    }
    else if (ui.rotateBox->currentIndex() == 2) {
        XFilter::Get()->Add(XTask{XTASK_ROTATE180});
    }
    else if (ui.rotateBox->currentIndex() == 3) {
        XFilter::Get()->Add(XTask{XTASK_ROTATE270});
    }

    // 图像镜像
    if (ui.flipBox->currentIndex() == 1) {
        XFilter::Get()->Add(XTask{XTASK_FLIPX});
    }
    else if (ui.flipBox->currentIndex() == 2) {
        XFilter::Get()->Add(XTask{XTASK_FLIPY});
    }
    else if (ui.flipBox->currentIndex() == 3) {
        XFilter::Get()->Add(XTask{XTASK_FLIPXY});
    }

}




