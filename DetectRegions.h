#ifndef DetectRegions_h
#define DetectRegions_h

#include <string.h>
#include <vector>

#include "Plate.h"
#include <opencv2/opencv.hpp>
//#include <cv.h>
//#include <highgui.h>
//#include <cvaux.h>

using namespace std;
using namespace cv;

class DetectRegions{
    public:
        DetectRegions();
        void setFilename(string f);
        vector<Plate> run(Mat input);

        // For generating XML training data 
        bool saveRegions;
        bool showSteps;
        
    private:
        string filename;
        vector<Plate> segment(Mat input);
        bool verifySizes(RotatedRect mr);
        Mat histeq(Mat in);
};

#endif
