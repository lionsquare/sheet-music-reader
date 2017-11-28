#include <iostream>
#include <vector>
#include "argparser.h"
#include "reader.h"
#include <opencv2/core.hpp>


using namespace std;
int main(int argc, char* argv[]) {
   
    // TODO - add option to run without displaying image

    ArgParser AP;
    vector<string> filenames = AP.parse_args(argc, argv);
    if (filenames.size() == 0) {
        cout<<"Must provide at least one image file as argument"<<endl;
        return -1;
    }


    const bool DISPLAY_FLAG = AP.get_display_flag();


    //cv::Mat M;
    //M = cv::Mat::zeros(10, 10, CV_64F);

    Reader R; 
    for (int a=0; a<filenames.size(); a++) {
    
        int err_code = R.import_file(filenames[a]);
        if (err_code == -1) {
            cout<<"File "<<filenames[a]<<" does not exist"<<endl;
        }
        else if (err_code == -2) {
            cout<<"No data in "<<filenames[a]<<endl;
        }

        if (DISPLAY_FLAG) {
            R.display_image();
        }
        R.preprocess();
        if (DISPLAY_FLAG) {
            R.display_image();
        }
        R.process();
        R.print_results();
        
    }

    
    return 0;
}
