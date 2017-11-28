#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include "reader.h"
#include "staff.h"
#include "staff_segr.h"


int const MAX_BINARY_VALUE = 255;

using namespace cv;


int Reader::import_file(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        return -1;
    }

    Reader::image = imread(filename.c_str(), 1);
    if (!image.data) {
        return -2;
    }

    return 0;
}

bool Reader::preprocess(void) {
    if (Reader::image.empty()) {
        return false;
    }

    // convert to grey
    if (Reader::image.channels() > 1) {
        cvtColor(Reader::image, Reader::image, CV_BGR2GRAY);
    }

    // TODO pick a more mathemagical way of thresholding
    // Threshold the image at 50% intensity
    int threshold_type = 0;
    threshold(Reader::image, Reader::image, MAX_BINARY_VALUE/2, 
            MAX_BINARY_VALUE, threshold_type);
    
    return true;
}

bool Reader::process(void) {
    // TODO add some type of preprocessing engine
    if (Reader::image.empty()) {
        return false;
    }
   
    /*
    StaffSegr segmenter;
    segmenter.segment(Reader::image);
*/

    std::cout<<"TODO: Process"<<std::endl;
    return true;
}


void Reader::print_results(void) {
    std::cout<<"TODO: Print Results"<<std::endl;
}

bool Reader::display_image(void) {
    if (Reader::image.empty()) {
        return false;
    }

    namedWindow("Display Image", WINDOW_AUTOSIZE);
    imshow("Display Image", Reader::image);
    waitKey(1500);
    return true;
}


bool Reader::set_image(Mat M) {
    Reader::image = M;
    return Reader::image.empty();
}
Mat Reader::get_image(void) {
    return Reader::image;
}
