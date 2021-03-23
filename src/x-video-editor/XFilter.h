#pragma once
#include<opencv2/core.hpp>
#include <vector>
enum XTasKType {
    XTASK_NONE,
    XTASK_GAIN,
    XTASK_ROTATE90,
    XTASK_ROTATE180,
    XTASK_ROTATE270,
    XTASK_FLIPX,
    XTASK_FLIPY,
    XTASK_FLIPXY,
    XTASK_RESIZE
};
struct XTask {
    XTasKType type;
    std::vector<double> para;
};

class XFilter {
public:
    virtual cv::Mat Filter(cv::Mat mat1, cv::Mat mat2) = 0;
    virtual void Add(XTask task) = 0;
    virtual void Clear() = 0;

    // 
    static XFilter* Get();

    virtual ~XFilter();
protected:
    XFilter();
};


