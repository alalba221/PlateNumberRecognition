#ifndef Plate_h
#define Plate_h

#include <string.h>
#include <vector>

#include <cv.h>
#include <highgui.h>
#include <cvaux.h>

using namespace std;
using namespace cv;

class Plate{
    public:
        Plate();
        Plate(Mat img, Rect pos);
        string str();
        
        //position of the plate in the picture
        Rect position;
        Mat plateImg;


        vector<char> chars;

        //position of each characters
        vector<Rect> charsPos;        
};

#endif
