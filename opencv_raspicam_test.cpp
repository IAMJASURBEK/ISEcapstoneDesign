#include <opencv2/core/core.hpp> 
#include <opencv2/imgcodecs.hpp> 
#include <opencv2/highgui/highgui.hpp> 
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <raspicam/raspicam_cv.h>

using namespace cv;
using namespace std;
int main()
{
Mat frame;
raspicam::RaspiCam_Cv capture;
capture.open();
while (1)
{
capture.grab();
capture.retrieve(frame);
imshow("Captured frame", frame);
if (waitKey(20) == 'q')
break;
}
capture.release();
return 0;
}

//Execution: 
// g++ opencv_raspicam_test.cpp -o opencv_raspicam_test -I/usr/local/include -L/usr/local/lib -L/opt/vc/lib -lraspicam -lraspicam_cv -lmmal -lmmal_core -lmmal_util `pkg-config --cflags --libs opencv4`

