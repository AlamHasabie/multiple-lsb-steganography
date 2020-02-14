#include "bmp/bmp.h"




using namespace std;


int main(){


    BMPFile file("files/test.bmp");

    file.write("files/test_output.bmp");

    // Read headers



    return 0;
}