#include <iostream>
#include "argparser.h"
#include "reader.h"

using namespace std;
int main(int argc, char* argv[]) {

    // TODO add support for multiple files

    ArgParser AP;
    string filename = AP.parse_args(argc, argv);
    if (filename == "") {
        cout<<"Must provide image file as argument"<<endl;
        return -1;
    }


    Reader R;
    int err_code = R.import_file(filename);
    if (err_code == -1) {
        cout<<"File "<<filename<<" does not exist"<<endl;
    }
    else if (err_code == -2) {
        cout<<"No data in "<<filename<<endl;
    }

    R.process();
    R.print_results();

    return 0;
}
