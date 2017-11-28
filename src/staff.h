#pragma once
#include <opencv2/opencv.hpp>

class Staff {
    public:
        Staff(cv::Mat new_img, int new_index);
    private:
        cv::Mat img;
        int index;
};
