#pragma once
#include <string>
#include <opencv2/opencv.hpp>

class Reader {
    public:
        int import_file(std::string filename);
        bool preprocess(void);
        bool process(void);
        void print_results(void);
        bool display_image(void);
        bool set_image(cv::Mat);
        cv::Mat get_image(void);
    private:
        cv::Mat image;
};
