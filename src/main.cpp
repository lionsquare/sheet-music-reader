#include <iostream>
#include <opencv2/highgui.hpp>

#include "argparser.h"
#include "reader.h"

using namespace std;
using namespace cv;
int main(int argc, char* argv[]) {

    // TODO add support for multiple files

    ArgParser AP;
    string filename = AP.parse_args(argc, argv);

    Reader R;
    R.import_file(filename);
    R.process();
    R.print_results();

    Mat A;
    return 0;
}
