#include <iostream>
#include <fstream>
#include "reader.h"
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;


bool Reader::import_file(std::string filename) {
    std::ifstream file(filename.c_str());
    if (!file.good()) {
        return false;
    }

    std::cout<<"TODO: Import File"<<std::endl;

    Mat image;
    image = imread(filename.c_str(), 1);

    return true;
}


bool Reader::process(void) {
    std::cout<<"TODO: Process"<<std::endl;
    return false;
}


void Reader::print_results(void) {
    std::cout<<"TODO: Print Results"<<std::endl;
}
