#include "bmp/bmp.h"
#include "vigenere/vigenere.h"
#include "stegano/stegano.h"
#include <iostream>

using namespace std;


int main(){


    BMPFile file("files/test.bmp");

    file.write("files/test_output.bmp");

    // Read headers
    cout << file.getImageSize() <<endl;

    cout << "message = " << file.getMessage() << endl;

    file.hideText("hallloween valentinee",2);
    file.unhideText(100,2);
    
    cout << "message = " << file.getMessage() << endl;
    //cout << file.getContent() << endl;

    return 0;
}