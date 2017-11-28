#include <iostream>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "reader.h"
#include "staff.h"
#include "staff_segr.h"


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


bool Reader::process(void) {
    // TODO add some type of preprocessing engine
    
    

    std::cout<<"TODO: Process"<<std::endl;
    return false;
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
    waitKey(1000);
    return true;
}


bool Reader::set_image(Mat M) {
    Reader::image = M;
    return Reader::image.empty();
}
Mat Reader::get_image(void) {
    return Reader::image;
}
