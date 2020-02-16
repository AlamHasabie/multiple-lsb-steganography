#include "bmp/bmp.h"
#include "vigenere/vigenere.h"
#include "stegano/stegano.h"
#include <iostream>

using namespace std;


int main(){


    BMPFile file("files/test.bmp");
    BMPFile file_2("files/test.bmp");

    float psnr;



    // Read headers

    cout << "message = " << file.getMessage() << endl;

    file.hideText("hallloween valentinee",2);
    file.unhideText(30,2);

    cout << "message = " << file.getMessage() << endl;
    //cout << file.getContent() << endl;

    psnr = file.PSNR(file_2);
    cout << "PSNR : " << psnr << endl;

    return 0;
}