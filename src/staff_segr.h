#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include "staff.h"

class StaffSegr {
    public:
        std::vector<Staff> segment(cv::Mat doc);
};
