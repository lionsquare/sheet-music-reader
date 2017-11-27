#include <string>
#include <opencv2/opencv.hpp>

class Reader {
    public:
        int import_file(std::string filename);
        bool process(void);
        void print_results(void);
        bool display_image(void);
        bool set_image(cv::Mat);
    private:
        cv::Mat image;
        //string file_name;
        //Reader::open_file();
        //Reader::import_image();
        //Reader::close_file();
};
