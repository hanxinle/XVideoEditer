#include "XVideoEditor.h"
#include <QtWidgets/QApplication>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;


int main (int argc, char *argv[]) {
    //test Opencv ==> OK
    //Mat img;
    //img = imread ("1.png");
    //namedWindow ("1.png");
    //imshow ("1.png", img);
    //waitKey (0);
    QApplication a (argc, argv);
    XVideoEditor w;
    w.show ();
    return a.exec ();
}
