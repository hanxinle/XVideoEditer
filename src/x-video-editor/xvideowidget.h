#pragma once
#include <opencv2/core.hpp>
#include <QOpenGLWidget>
#include <QImage>

class XVideoWidget :public QOpenGLWidget {

    Q_OBJECT

public:
    XVideoWidget(QWidget * w);
    ~XVideoWidget();
    void paintEvent(QPaintEvent * e);

public slots:
    void SetImage(cv::Mat mat);
protected:
    QImage img;
};
