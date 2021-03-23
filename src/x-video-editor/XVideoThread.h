#pragma once
#include <opencv2/core.hpp>
#include <QThread>
#include <string>
#include <QMutex>
class XVideoThread :public QThread {

    Q_OBJECT

public:


    bool Open(std::string file);

    void run();
    static XVideoThread* Get() {
        static XVideoThread vt;
        return &vt;
    }

    ~XVideoThread();
signals:
    // src 源视频显示
    void ViewImage1(cv::Mat mat);
    // src2 视频融合的第二个图片源的显示
    void ViewImage2(cv::Mat mat);

    // 显示生成后图像
    void ViewDes(cv::Mat mat);
protected:
    QMutex mutex;
    XVideoThread();
};

