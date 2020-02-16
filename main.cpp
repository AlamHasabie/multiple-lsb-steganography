#include "bmp/bmp.h"
#include "vigenere/vigenere.h"
#include "stegano/stegano.h"
#include <iostream>

using namespace std;


int main(){


    BMPFile file("files/test.bmp");



    // Read headers
    cout << file.getImageSize() <<endl;

    cout << "message = " << file.getMessage() << endl;

    file.hideText("hallloween valentinee",2);
    file.unhideText(30,2);
    
    cout << "message = " << file.getMessage() << endl;
    //cout << file.getContent() << endl;

    file.write("files/test_output.bmp");

    return 0;
}