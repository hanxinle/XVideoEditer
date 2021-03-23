// 视频是在 QThread 中打开
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <QThread>
#include <string>
#include <QMutex>

class XVideoThread : public QThread {
    Q_OBJECT
public:
    // 这样对象会有唯一性
    static XVideoThread* Get() {
        static XVideoThread xv;
        return &xv;
    }

    bool Open(const std::string file);

    ~XVideoThread() { }
    // 线程入口函数
    void run();
signals:
    void ViewImage1(cv::Mat mat);
protected:
    QMutex mutex;
    XVideoThread() { }
};

